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
	int n, m, sum = 0;
	scanf("%d", &n);
	vector<int> dis;  // 记录每个点到初始点(1号)的距离，前缀和
	dis.resize(n + 2);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		sum += tmp;
		dis[i + 1] = sum;  // 因为是记录到第一个点的距离，就从第二个点开始，所以下标为 i + 1
	}
	scanf("%d", &m);
	int a, b, t;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a > b) swap(a, b);
		t = dis[b] - dis[a];
		printf("%d\n", min(t, sum - t));
	}
	return 0;
}
