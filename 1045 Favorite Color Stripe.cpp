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
	scanf("%d %d", &n, &m);  // 这里的n是多余信息，没有
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		book[x] = i;  // 给特定颜色序列按递增编号
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d", &x);
		if (book[x] >= 1) {  // 剔除那些不在喜欢的序列中的颜色
			a[num++] = book[x];  // 将剔除后的序列编号，1最小，m最大
		}
	}  // 至此，题目被转化成立“求最长不下降子序列”的问题，原序列就是a，长度为num
	/*由于这道题的数据量是1e4，可以用n2的方法AC，但1e4是极限了，再大就要换成下面那个nlogn的写法
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
	d[1] = a[0];  //初始化 
	maxn = 1;
	for (int i = 1; i < num; i++) { 
		if (d[maxn] <= a[i]) {  //如果可以接在len后面就接上
			d[++maxn] = a[i];
		}
		else {  //否则就找一个最该替换的替换掉 
			int j = upper_bound(d + 1, d + maxn + 1, a[i]) - d;  //找到第一个大于它的d的下标 
			d[j] = a[i];
		}
	}
	printf("%d", maxn);
	return 0;
}
