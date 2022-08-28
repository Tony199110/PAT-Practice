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
	if (!a.flag || !b.flag) {  // ���κ�һ������������
		return a.flag > b.flag;  // ��false�ŵ�����ȥ
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
		node[a] = { a, b, c, false };  // ��Щ�ڵ㲻����������
	}
	for (int i = s; i != -1; i = node[i].next) {  // ����ʼ�ڵ����һ������
		node[i].flag = true;  // ��������ı��Ϊtrue
		cnt++;  // ��ͳ��������
	}
	if (cnt == 0) {  // ����Ϊ�յ����
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
