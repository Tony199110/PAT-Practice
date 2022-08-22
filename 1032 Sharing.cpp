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
	}  // �������
	for (int i = s1; i != -1; i = node[i].next) {  // ������һ������
		node[i].flag = true;  // ����һ�����е�flag��Ϊtrue���൱�ھ�����һ��
	}
	for (int i = s2; i != -1; i = node[i].next) {
		if (node[i].flag == true) {  // ������һ��true��˵�����ߴ����￪ʼ�ظ��������˵ڶ���
			printf("%05d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}