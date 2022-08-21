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
	char c[81], u[30][30];
	memset(u, ' ', sizeof(u));  // 初始化输出全为空格
	scanf("%s", c);  // 输入字符串
	int n = strlen(c) + 2;
	int n1 = n / 3, n2 = n / 3 + n % 3, index = 0;
	for (int i = 0; i < n1; i++) u[i][0] = c[index++];  // 输出左边一列
	for (int i = 1; i < n2 - 1; i++) u[n1 - 1][i] = c[index++];  // 输出除左右边上2个的底部
	for (int i = n1 - 1; i >= 0; i--) u[i][n2 - 1] = c[index++];  // 输出右边一列
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			printf("%c", u[i][j]);
		}
		printf("\n");
	}
	return 0;
}