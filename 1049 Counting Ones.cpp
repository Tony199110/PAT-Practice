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
	int n, base = 10, sum = 0;
	scanf("%d", &n);
	sum += (n - 1) / 10 + 1;
	while (n >= base) {
		sum += ((n - base) / (10 * base) + 1) * base;
		if (n % (10 * base) <= (base * 2 - 1) && n % (10 * base) >= base) {
			sum -= (base - (n + 1) % base);
		}
		base *= 10;
	}
	printf("%d", sum);
	return 0;
}
