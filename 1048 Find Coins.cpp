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
int main() {
	int n, m;
	int vec[100005];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &vec[i]);
	}
	sort(vec, vec + n);
	for (int i = 0; i < n - 1; i++) {
		int j = lower_bound(vec + i + 1, vec + n, m - vec[i]) - vec;
		if (vec[i] + vec[j] == m) {
			printf("%d %d", vec[i], vec[j]);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}*/
int a[501];  // 记录每个数字出现的次数
int main() {
	int n, m, temp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		a[temp]++;  // 记录每个面值为temp的硬币的个数
	}
	for (int i = 0; i < 501; i++) {
		if (a[i]) {
			a[i]--;
			if (m > i && a[m - i]) {
				printf("%d %d", i, m - i);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0;
}
