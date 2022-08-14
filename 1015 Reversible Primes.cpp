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
	while (scanf("%d", &n) != EOF) {  // ��������������������
		if (n < 0) break;
		scanf("%d", &radix);
		if (isprime(n) == false) {
			printf("No\n");
			continue;
		}
		int len = 0, arr[100];
		do {  // ����ֵ��λ��ȡ�������д洢���±�С���ǵ�λ������Ϊlen
			arr[len++] = n % radix;
			n = n / radix;
		} while (n != 0);
		for (int i = 0; i < len; i++) {
			n = n * radix + arr[i];  // ����λ�洢��radix���Ƶ���ת��Ϊʮ����
		}
		printf("%s", isprime(n) ? "Yes\n" : "No\n");
	}
	return 0;
}