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
	int a[3], b[3], c[3];
	scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
	scanf("%d.%d.%d", &b[0], &b[1], &b[2]);
	c[2] = (a[2] + b[2]) % 29;
	c[1] = (a[1] + b[1] + (a[2] + b[2]) / 29) % 17;
	c[0] = a[0] + b[0] + (a[1] + b[1] + (a[2] + b[2]) / 29) / 17;
	printf("%d.%d.%d", c[0], c[1], c[2]);
	return 0;
}
