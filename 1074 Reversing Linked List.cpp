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
	}  // 至此，输入完成，存在了结构体数组里
	address = first;  // 遍历一遍先，有可能部分节点不在链表里
	int cnt = 0;
	while (address != -1) {
		list[cnt] = address;  // 把链表的节点的地址存到数组list中，那么接下来就可以通过操作地址来操作节点
		address = node[address].next;
		cnt++;
	}
	for (int i = 0; i < cnt - (k - 1); i += k) {  // 每k个进行翻转
		for (int h = 0; h < k / 2; h++) {  // 翻转k个节点，只需进行k/2次交换即可
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

