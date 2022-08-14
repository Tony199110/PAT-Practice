# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

bool isprime(int n) {
	if (n <= 1) return false;
	int sqr = int(sqrt(n * 1.0));
	for (int i = 2; i <= sqr; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n, radix;
	while (scanf("%d", &n) != EOF) {  // 处理不给数据组数的输入
		if (n < 0) break;
		scanf("%d", &radix);
		if (isprime(n) == false) {
			printf("No\n");
			continue;
		}
		int len = 0, arr[100];
		do {  // 将数值逐位提取到数组中存储，下标小的是低位，长度为len
			arr[len++] = n % radix;
			n = n / radix;
		} while (n != 0);
		for (int i = 0; i < len; i++) {
			n = n * radix + arr[i];  // 将逐位存储的radix进制的数转化为十进制
		}
		printf("%s", isprime(n) ? "Yes\n" : "No\n");
	}
	return 0;
}