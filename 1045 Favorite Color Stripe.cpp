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

int book[201], a[10001], dp[10001];
int d[10001];

int main() {
	int n, m, x, l, num = 0, maxn = 0;
	scanf("%d %d", &n, &m);  // �����n�Ƕ�����Ϣ��û��
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		book[x] = i;  // ���ض���ɫ���а��������
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d", &x);
		if (book[x] >= 1) {  // �޳���Щ����ϲ���������е���ɫ
			a[num++] = book[x];  // ���޳�������б�ţ�1��С��m���
		}
	}  // ���ˣ���Ŀ��ת��������������½������С������⣬ԭ���о���a������Ϊnum
	/*������������������1e4��������n2�ķ���AC����1e4�Ǽ����ˣ��ٴ��Ҫ���������Ǹ�nlogn��д��
	// n2
	for (int i = 0; i < num; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] >= a[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		maxn = max(maxn, dp[i]);
	} */
	// nlogn
	d[1] = a[0];  //��ʼ�� 
	maxn = 1;
	for (int i = 1; i < num; i++) { 
		if (d[maxn] <= a[i]) {  //������Խ���len����ͽ���
			d[++maxn] = a[i];
		}
		else {  //�������һ������滻���滻�� 
			int j = upper_bound(d + 1, d + maxn + 1, a[i]) - d;  //�ҵ���һ����������d���±� 
			d[j] = a[i];
		}
	}
	printf("%d", maxn);
	return 0;
}
