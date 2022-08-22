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

struct NODE {
	char key;
	int next;
	bool flag;
} node[100005];

int main() {
	int s1, s2, n, a, b;
	scanf("%d %d %d", &s1, &s2, &n);
	char data;
	for (int i = 0; i < n; i++) {
		scanf("%d %c %d", &a, &data, &b);
		node[a] = { data, b, false };
	}  // 输入完成
	for (int i = s1; i != -1; i = node[i].next) {  // 遍历第一个序列
		node[i].flag = true;  // 将第一个序列的flag置为true，相当于均遇到一次
	}
	for (int i = s2; i != -1; i = node[i].next) {
		if (node[i].flag == true) {  // 碰到第一个true就说明二者从这里开始重复，遇到了第二次
			printf("%05d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}