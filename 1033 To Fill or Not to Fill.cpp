# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <set>
# include <algorithm>
# include <string>
# include <cstring>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

const int inf = 99999999;
struct station {
	double price, dis;  // ÿ������վ���ͼۺ;���ʼ�����
};
bool cmp1(station a, station b) {
	return a.dis < b.dis;
}

int main() {
	double cmax, d, davg;
	int n;
	scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
	vector<station> sta(n + 1);
	sta[0] = { 0.0, d };
	for (int i = 1; i <= n; i++) {
		scanf("%lf %lf", &sta[i].price, &sta[i].dis);
	}  // �������
	sort(sta.begin(), sta.end(), cmp1);
	double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;
	if (sta[0].dis != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;  // ��������������һվ������ʼ�㴦����û���;Ϳ�������
	}
	else {
		nowprice = sta[0].price;  // ��ʼ����ǰ�ͼ�Ϊ��ʼ���ͼ�
	}
	while (nowdis < d) {  // û�ߵ��յ�ͼ���
		maxdis = nowdis + cmax * davg;  // ���������ܵ�������
		double minPriceDis = 0.0, minPrice = inf;
		int flag = 0;
		for (int i = 1; i <= n && sta[i].dis <= maxdis; i++) {  // ȥ�����ܵ���ļ���վ
			if (sta[i].dis <= nowdis) continue;  // �����Ѿ��߹��ļ���վ
			// ���һ
			if (sta[i].price < nowprice) {  // ��������м���վ���ͼ۱ȵ�ǰ�ı��ˣ���ȥ������Ǹ�����׬
				totalPrice += nowprice * (sta[i].dis - nowdis - leftdis) / davg;  // �ͼ� * ����������
				leftdis = 0.0;
				nowprice = sta[i].price;
				nowdis = sta[i].dis;
				flag = 1;
				break;
			}
			if (sta[i].price < minPrice) {  // ���û�д�׬���������ȥ�Ҿ����ܵ͵��ͼ�
				minPrice = sta[i].price;
				minPriceDis = sta[i].dis;
			}
		}
		// �����
		if (flag == 0 && minPrice != inf) {  // û�бȵ�ǰ����վ���͵��ͼۣ�ֻ��ȥ������͵��Ǹ�����վ�������������ٿ�һ��
			totalPrice += nowprice * (cmax - leftdis / davg);  // �ͼ� * (�������������� = �������� - �ϴ�ʣ�µ���)
			leftdis = cmax * davg - (minPriceDis - nowdis);  // 
			nowprice = minPrice;
			nowdis = minPriceDis;
		}
		// �����
		if (flag == 0 && minPrice == inf) {  // �������޷��ִﲻ����һ����վ��Ϊ���ɴ�����
			nowdis += cmax * davg;  // ���Լ������ܿ���Զ����Զ
			printf("The maximum travel distance = %.2lf", maxdis);
			return 0;
		}
	}
	printf("%.2lf", totalPrice);
	return 0;
}