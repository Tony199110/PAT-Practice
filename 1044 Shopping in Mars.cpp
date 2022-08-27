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
/*
int n, m;
vector<int> sum, resultArr;
void Func(int i, int& j, int& tempsum) {
	int left = i, right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		if (sum[mid] - sum[i - 1] >= m)
			right = mid;
		else
			left = mid + 1;
	}
	j = right;
	tempsum = sum[j] - sum[i - 1];
}
int main() {
	scanf("%d%d", &n, &m);
	sum.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];  // ����ʱֱ�Ӵ�ӵ�1��λ�ÿ�ʼ���ۼӺ�
	}
	int minans = sum[n];
	for (int i = 1; i <= n; i++) {
		int j, tempsum;
		Func(i, j, tempsum);  // �����i��������j�����ĺ�tempsum����ʹ����͵��ڻ�ӽ�Ŀ��ֵm
		if (tempsum > minans) continue;
		if (tempsum >= m) {  // �ںʹ��ڵ���Ŀ��ֵm�������
			if (tempsum < minans) {  // ѡ����С���Ǹ�m
				resultArr.clear();
				minans = tempsum;
			}
			resultArr.push_back(i);
			resultArr.push_back(j);  // ����Ϊһ�����
		}
	}
	for (int i = 0; i < resultArr.size(); i += 2) {
		printf("%d-%d\n", resultArr[i], resultArr[i + 1]);
	}
	return 0;
}
*/

int a[100005], ans[100005];
int n, m, k = 0;
int minn = 999999999;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int l = 1, r = 1;
	int s = 0;
	while (l <= n) {
		while (s < m && r <= n) {
			s += a[r];
			r++;
		}
		if (s < m) break;
		else if (s < minn) {
			k = 0;
			ans[++k] = l;
			ans[++k] = r - 1;  // ����Ϊһ���
			minn = s;
		}
		else if (s == minn) {
			ans[++k] = l;
			ans[++k] = r - 1;  // ��ӵ�һ��rҪ��ȥ
		}
		s -= a[l];
		l++;  // ��ָ������һλ����ָ�벻��Ҫ��
	}
	for (int i = 1; i <= k; i += 2) {
		printf("%d-%d\n", ans[i], ans[i + 1]);
	}
	return 0;
}
