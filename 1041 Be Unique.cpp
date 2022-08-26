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

int a[100010], b[10010];  // 用下标索引输入的数字
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (b[a[i]] == 1) {
			printf("%d", a[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}