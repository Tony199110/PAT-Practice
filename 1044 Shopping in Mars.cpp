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
		sum[i] += sum[i - 1];  // 输入时直接存从第1个位置开始的累加和
	}
	int minans = sum[n];
	for (int i = 1; i <= n; i++) {
		int j, tempsum;
		Func(i, j, tempsum);  // 求出第i个数到第j个数的和tempsum，并使这个和等于或接近目标值m
		if (tempsum > minans) continue;
		if (tempsum >= m) {  // 在和大于等于目标值m的情况下
			if (tempsum < minans) {  // 选择最小的那个m
				resultArr.clear();
				minans = tempsum;
			}
			resultArr.push_back(i);
			resultArr.push_back(j);  // 两个为一组输出
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
			ans[++k] = r - 1;  // 两个为一组答案
			minn = s;
		}
		else if (s == minn) {
			ans[++k] = l;
			ans[++k] = r - 1;  // 多加的一次r要减去
		}
		s -= a[l];
		l++;  // 左指针右移一位，右指针不需要动
	}
	for (int i = 1; i <= k; i += 2) {
		printf("%d-%d\n", ans[i], ans[i + 1]);
	}
	return 0;
}
