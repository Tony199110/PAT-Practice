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

map<int, int> pic;
int main() {
	int m, n, tmp, maxn = 0;
	scanf("%d %d", &m, &n);
	int half = m * n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			pic[tmp]++;
			if (pic[tmp] > half) {
				printf("%d", tmp);
				return 0;
			}
		}
	}
	/*
	for (auto it : pic) {
		if (maxn < it.second) {
			maxn = it.second;
			tmp = it.first;
		}
	}
	printf("%d", tmp); */
	return 0;
}
