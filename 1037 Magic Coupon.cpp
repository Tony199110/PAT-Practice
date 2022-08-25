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

int main() {
	int m, n, ans = 0, p = 0, q = 0;
	scanf("%d", &m);
	vector<int> v1(m);
	for (int i = 0; i < m; i++) scanf("%d", &v1[i]);
	scanf("%d", &n);
	vector<int> v2(n);
	for (int i = 0; i < n; i++) scanf("%d", &v2[i]);  // 完成输入
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());  // 从小到大排序
	while (p < m && q < n && v1[p] < 0 && v2[q] < 0) {  // 先将负数两两相乘
		ans += v1[p] * v2[q];
		p++;
		q++;
	}
	p = m - 1;
	q = n - 1;
	while (p >= 0 && q >= 0 && v1[p] > 0 && v2[q] > 0) {  // 先将正数两两相乘
		ans += v1[p] * v2[q];
		p--;
		q--;
	}
	printf("%d", ans);
	return 0;
}