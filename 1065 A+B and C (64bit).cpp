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
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		long long sum = a + b;
		if (a > 0 && b > 0 && sum < 0)  // 说明上溢出了，肯定比c大
			printf("Case #%d: true\n", i + 1);
		else if (a < 0 && b < 0 && sum >= 0)  // 说明下溢出了，肯定比c小
			printf("Case #%d: false\n", i + 1);
		else if (sum > c)
			printf("Case #%d: true\n", i + 1);
		else
			printf("Case #%d: false\n", i + 1);
	}
	return 0;
}
