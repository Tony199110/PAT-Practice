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

long long gcd(long long a, long long b) {  // �������
	return b == 0 ? abs(a) : gcd(b, a % b);  // ���������a����Զ��b��a%b���Լ�С���Ĵ�С����ֹ���
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
		gcdvalue = gcd(suma, sumb);  // ÿ��һ���ͽ���Լ�֣���ֹ���
		suma /= gcdvalue;
		sumb /= gcdvalue;
	}
	long long integer = suma / sumb;  // ȡ��������
	suma -= integer * sumb;  // �����ˣ�׼�������
	if (integer != 0) {  // ��������
		printf("%lld", integer);
		if (suma != 0) printf(" ");
	}
	if (suma != 0)  // С�����֣��������
		printf("%lld/%lld", suma, sumb);
	if (integer == 0 && suma == 0)
		printf("0");
	return 0;
}

