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

long long gcd(long long a, long long b) {  // 最大公因数
	return b == 0 ? abs(a) : gcd(b, a % b);  // 由于这道题a可能远比b大，a%b可以减小数的大小，防止溢出
}
int main() {
	long long n, a, b, suma = 0, sumb = 1, gcdvalue;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld/%lld", &a, &b);
		gcdvalue = gcd(a, b);
		a /= gcdvalue;
		b /= gcdvalue;
		suma = a * sumb + b * suma;
		sumb = b * sumb;
		gcdvalue = gcd(suma, sumb);  // 每加一个就进行约分，防止溢出
		suma /= gcdvalue;
		sumb /= gcdvalue;
	}
	long long integer = suma / sumb;  // 取整数部分
	suma -= integer * sumb;  // 算完了，准备输出了
	if (integer != 0) {  // 整数部分
		printf("%lld", integer);
		if (suma != 0) printf(" ");
	}
	if (suma != 0)  // 小数部分，即真分数
		printf("%lld/%lld", suma, sumb);
	if (integer == 0 && suma == 0)
		printf("0");
	return 0;
}

