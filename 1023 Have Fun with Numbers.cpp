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

int book[10]; // ��¼ÿ�����ֵĸ���

int main() {
	char num[22];
	scanf("%s", num);
	int flag = 0, len = strlen(num);  // ���ɶ���char���鲢�һ�ȡ�䳤��
	for (int i = len - 1; i >= 0; i--) {  // �Ӹ�λ��ʼ
		int temp = num[i] - '0';  // ȡ��һ����λ
		book[temp]++;  // ����λ��1
		temp = temp * 2 + flag;  // flag�ǽ�λ���ı�־
		flag = 0;
		if (temp >= 10) {
			temp = temp - 10;
			flag = 1;
		}
		num[i] = temp + '0';  // ����2�����λ
		book[temp]--;  // ����2�����λ��1
	}
	int flag1 = 0;
	for (int i = 0; i < 10; i++) {
		if (book[i] != 0) {
			flag1 = 1;
			break;
		}
	}
	printf("%s", (flag == 1 || flag1 == 1) ? "No\n" : "Yes\n");
	if (flag == 1) printf("1");  // ���λ��λ�˵����
	printf("%s", num);
	return 0;
}