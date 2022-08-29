# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <set>
# include <stack>
# include <algorithm>
# include <string>
# include <cstring>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

// 质因子的存储
struct Factor {
	int x;  // 质因子
	int c;  // count质因子数目
} fac[20];  // 对于int类型的，前10个质数就超过了int范围
int k = 0;  // 质因子个数

// 素数表 埃式筛法
const int maxn = 50000;
int prime[maxn];  // 质数表
int p[maxn];  // 对p[i]，i是素数
int num = 0;  // 质数个数

void prime_find() {  // 一种我闻所未闻的找素数写法
	for (int i = 2; i < maxn; i++) {
		if (p[i] == 1) continue;  // i不是素数，下一个数
		prime[num++] = i;
		for (int j = 2 * i; j < maxn; j += i)
			p[j] = 1;  // 将当前素数的所有倍数置为非素数
	}
}

void factorization2(int n) {  // 质因子分解
	for (int i = 0; n > 1; i++) {
		if (n % prime[i] == 0) {  // 如果有一个质数prime[i]是n的因子
			fac[k].x = prime[i];  // 加入这个质因子
			fac[k].c = 0;  // 并初始化其个数为0
			while (n % prime[i] == 0) {  // 尽力去除以这个质因子，直到除不尽
				fac[k].c++;  // 记录这个质因子的个数
				n /= prime[i];
			}
			k++;  // 记录质因子的总数k
		}
	}
}

int main() {
	prime_find();  // 获取素数表
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("1=1");
		return 0;
	}
	factorization2(n);
	printf("%d=", n);
	for (int i = 0; i < k; i++) {
		if (i != 0) printf("*");
		printf("%d", fac[i].x);
		if (fac[i].c > 1) {
			printf("^%d", fac[i].c);
		}
	}
	return 0;
}
