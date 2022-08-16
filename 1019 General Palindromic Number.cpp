# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

int main() {
	int n, radix;
	scanf("%d %d", &n, &radix);
	int len = 0, arr[100];
	do {  // 将数值逐位提取到数组中存储，下标小的是低位，长度为len
		arr[len++] = n % radix;
		n = n / radix;
	} while (n != 0);
	int flag = 0;
	for (int i = 0; i < len / 2; i++) {
		if (arr[i] != arr[len - i - 1]) {
			printf("No\n");
			flag = 1;
			break;
		}
	}
	if (!flag) printf("Yes\n");
	printf("%d", arr[len - 1]);
	for (int i = len - 2; i >= 0; i--) {
		printf(" %d", arr[i]);
	}
	return 0;
}