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

int in[1010], level[1010], n, t = 0;
void inOrder(int root) {  // 中序遍历，只有满二叉树才能这么写，满二叉树可以由根的下标得到左右子树根的下标
	if (root >= n) return;
	inOrder(root * 2 + 1);  // 左
	level[root] = in[t++];  // 根；root是按照层序遍历的从上到下、从左到右的顺序编号的，即整棵树的根节点的编号为0；t在这里面才是实实在在地遍历每一个节点
	inOrder(root * 2 + 2);  // 右
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	sort(in, in + n);
	inOrder(0);
	printf("%d", level[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", level[i]);
	return 0;
}
