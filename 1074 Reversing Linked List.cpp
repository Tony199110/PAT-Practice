# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <stack>
# include <set>
# include <algorithm>
# include <string>
# include <cstring>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

const int maxn = 100010;
struct NODE {
	int data;
	int next;
};
struct NODE node[maxn];
int list[maxn];
int first, n, k, temp;
int main() {
	scanf("%d %d %d", &first, &n, &k);
	int address, data, next;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next;
	}  // ���ˣ�������ɣ������˽ṹ��������
	address = first;  // ����һ���ȣ��п��ܲ��ֽڵ㲻��������
	int cnt = 0;
	while (address != -1) {
		list[cnt] = address;  // ������Ľڵ�ĵ�ַ�浽����list�У���ô�������Ϳ���ͨ��������ַ�������ڵ�
		address = node[address].next;
		cnt++;
	}
	for (int i = 0; i < cnt - (k - 1); i += k) {  // ÿk�����з�ת
		for (int h = 0; h < k / 2; h++) {  // ��תk���ڵ㣬ֻ�����k/2�ν�������
			temp = list[i + h];
			list[i + h] = list[i + k - h - 1];
			list[i + k - h - 1] = temp;
		}
	}
	for (int i = 0; i < cnt - 1; i++) {
		printf("%05d %d %05d\n", list[i], node[list[i]].data, list[i + 1]);
	}
	printf("%05d %d -1", list[cnt - 1], node[list[cnt - 1]].data);
	return 0;
}

