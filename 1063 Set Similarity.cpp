# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <stack>
# include <set>
# include <algorithm>
# include <string>
# include <cstring>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

int main() {
	int n, m, k, temp, a, b;
	scanf("%d", &n);
	vector<set<int>> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		set<int> s;
		for (int j = 0; j < m; j++) {
			scanf("%d", &temp);
			s.insert(temp);
		}
		v[i] = s;
	}  // 至此输入完成，set会自己去重并排序的
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		int nc = 0, nt = v[b - 1].size();
		for (auto it = v[a - 1].begin(); it != v[a - 1].end(); it++) {
			if (v[b - 1].find(*it) == v[b - 1].end())  // find函数没找到，就会返回end()
				nt++;
			else
				nc++;
		}
		double ans = (double)nc / nt * 100;
		printf("%.1lf%%\n", ans);
	}
	return 0;
}
