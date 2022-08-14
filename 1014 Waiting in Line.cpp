# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

struct node {
	int poptime, endtime;  // poptime������׵��˳��ӵ�ʱ�䣬endtime�����β���˳��ӵ�ʱ��
	queue<int> q;  // ��ʾ��ǰ���ڵ��ŶӶ���
};

int main() {
	int n, m, k, q, index = 1;  // index�Ǳ���k���ͻ�����ʱ���õģ��ᴩȫ��
	scanf("%d %d %d %d", &n, &m, &k, &q);
	vector<int> time(k + 1), result(k + 1);  // ���鲻���ñ���k��������vector����
	for (int i = 1; i <= k; i++) {
		scanf("%d", &time[i]);
	}
	vector<node> window(n + 1); // Ϊÿ�����ڶ�ά��һ������
	vector<bool> sorry(k + 1, false);  // 
	for (int i = 1; i <= m; i++) {  // �������ڶ�������������װ�ڶ��ţ�
		for (int j = 1; j <= n; j++) {  // �������ڣ�����װ��һ�ţ�
			if (index <= k) {  // ���ڽض�k<n*m�������k>n*mʱ�����if��һֱ����
				window[j].q.push(time[index]);  // ��ʼ�������ͻ�һ����װ��������
				if (window[j].endtime >= (17 - 8) * 60) {
					sorry[index] = true;  // ����ǰ�ö��ж�β���ӵ�ʱ�̳�����17�㣬������ӵ���ֻ��sorry
				}
				window[j].endtime += time[index];  // ÿ���һ���˾�Ҫ���µ�ǰ���е�endtime
				if (i == 1) {
					window[j].poptime = window[j].endtime;
				}
				result[index] = window[j].endtime;
				index++;
			}
		}
	}  // ���ˣ���ʼ����ɣ����������ڵ���������
	while (index <= k) {  // ��������û�ˣ������while�Ͳ��ý�ȥ
		int tempmin = window[1].poptime, tempwindow = 1;
		for (int i = 2; i <= n; i++) {
			if (window[i].poptime < tempmin) {  // �Ҷ�������������ĸ�����
				tempmin = window[i].poptime;
				tempwindow = i;
			}
		}
		window[tempwindow].q.pop();  // �ҵ�����������Ŀͻ�����������
		window[tempwindow].q.push(time[index]);  // ���Ӻ��û��������һ���ͻ������������
		window[tempwindow].poptime += window[tempwindow].q.front();
		if (window[tempwindow].endtime >= (17 - 8) * 60) {
			sorry[index] = true;
		}
		window[tempwindow].endtime += time[index];
		result[index] = window[tempwindow].endtime;
		index++;
	}  // ���ˣ����k���ͻ��ķ���
	for (int i = 1; i <= q; i++) {
		int query, minute;
		scanf("%d", &query);
		minute = result[query];
		if (sorry[query] == true) {
			printf("Sorry\n");
		}
		else {
			printf("%02d:%02d\n", minute / 60 + 8, minute % 60);
		}
	}
	return 0;
}