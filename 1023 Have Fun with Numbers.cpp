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

int book[10]; // 记录每个数字的个数

int main() {
	char num[22];
	scanf("%s", num);
	int flag = 0, len = strlen(num);  // 轻松读入char数组并且获取其长度
	for (int i = len - 1; i >= 0; i--) {  // 从个位开始
		int temp = num[i] - '0';  // 取出一个数位
		book[temp]++;  // 该数位加1
		temp = temp * 2 + flag;  // flag是进位与否的标志
		flag = 0;
		if (temp >= 10) {
			temp = temp - 10;
			flag = 1;
		}
		num[i] = temp + '0';  // 乘以2后的数位
		book[temp]--;  // 乘以2后的数位减1
	}
	int flag1 = 0;
	for (int i = 0; i < 10; i++) {
		if (book[i] != 0) {
			flag1 = 1;
			break;
		}
	}
	printf("%s", (flag == 1 || flag1 == 1) ? "No\n" : "Yes\n");
	if (flag == 1) printf("1");  // 最高位进位了的情况
	printf("%s", num);
	return 0;
}