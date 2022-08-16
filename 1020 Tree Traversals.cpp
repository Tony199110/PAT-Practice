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

vector<int> post, in;
map<int, int> level;  // map是有序的，它自己会根据index从小到大排序

void pre(int root, int start, int end) {  // 已知后序和中序求前序的函数，root是对后续说的，start和end是对中序说的
	if (start > end) return;
	int i = start;
	while (i < end && in[i] != post[root]) i++;
	printf("%d ", post[root]);
	pre(root - (end - i) - 1, start, i - 1);  // post中的根节点下标减去右子树长度，再减去根的长度1，就是左子树长度，也是其根节点的下标
	pre(root - i, i + 1, end);
}

void pre2(int root, int start, int end, int index) {  // 已知后序和中序求层序的函数，基于pre修改而来
	if (start > end) return;
	int i = start;
	while (i < end && in[i] != post[root]) i++;
	level[index] = post[root];  // index表示当前节点在二叉树中所对应的下标
	pre2(root - (end - i) - 1, start, i - 1, 2 * index + 1);
	pre2(root - 1, i + 1, end, 2 * index + 2);
}

int main() {
	int n;
	scanf("%d", &n);
	post.resize(n);  // 若用push_back初始化vector，就不需要resize给定大小
	in.resize(n);  // 因为下面2行是用下标访问初始化vector的，所以必须要resize指明其大小，否则报错
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);  
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	pre2(n - 1, 0, n - 1, 0);
	auto it = level.begin();
	printf("%d", it->second);
	while (++it != level.end()) printf(" %d", it->second);
	return 0;
}