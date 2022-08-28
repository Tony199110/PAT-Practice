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
	int address, key, next;
	bool flag;
} node[100001];
bool cmp1(NODE a, NODE b) {
	if (!a.flag || !b.flag) {  // 有任何一方不在链表内
		return a.flag > b.flag;  // 把false放到后面去
	}
	else {
		return a.key < b.key;
	}
}

int main() {
	int n, cnt = 0, s, a, b, c;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		node[a] = { a, b, c, false };  // 有些节点不在链表里面
	}
	for (int i = s; i != -1; i = node[i].next) {  // 从起始节点遍历一次链表
		node[i].flag = true;  // 在链表里的标记为true
		cnt++;  // 并统计链表长度
	}
	if (cnt == 0) {  // 链表为空的情况
		printf("0 -1");
	}
	else {
		sort(node, node + 100001, cmp1);
		printf("%d %05d\n", cnt, node[0].address);
		for (int i = 0; i < cnt - 1; i++) {
			printf("%05d %d %05d\n", node[i].address, node[i].key, node[i + 1].address);
		}
		printf("%05d %d -1", node[cnt - 1].address, node[cnt - 1].key);
	}
	return 0;
}
