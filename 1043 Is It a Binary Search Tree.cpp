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

vector<int> pre, post, vec;  // 二叉搜索树的先序、后序、初始序列
struct node {
	int data;
	struct node* left, * right;
};

struct node* root = NULL;  // 初始化根节点地址为NULL
node* insert(node* root, int data) {  // 形参分别是当前树的根结点地址，要插入的节点值
	if (root == NULL) {
		root = new node();
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}
	else if (data < root->data) {
		root->left = insert(root->left, data);
		return root;
	}
	else if (data >= root->data) {
		root->right = insert(root->right, data);
		return root;
	}
}
void preorder1(node* root) {
	if (root != NULL) {
		pre.push_back(root->data);  // 根
		preorder1(root->left);  // 左
		preorder1(root->right);  // 右
	}
}
void postorder1(node* root) {
	if (root != NULL) {
		postorder1(root->left);  // 左
		postorder1(root->right);  // 右
		post.push_back(root->data);  // 根
	}
}
void preorder2(node* root) {  // 前序序列的镜像序列
	if (root != NULL) {
		pre.push_back(root->data);  // 根
		preorder2(root->right);  // 右
		preorder2(root->left);  // 左
	}
}
void postorder2(node* root) {
	if (root != NULL) {
		postorder2(root->right);  // 右
		postorder2(root->left);  // 左
		post.push_back(root->data);  // 根
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		vec.push_back(temp);
		root = insert(root, temp);  //构建出一棵二叉搜索树
	}
	// 判断初始序列是否是先序序列
	pre.clear();
	preorder1(root);
	int i = 0;
	for (i = 0; i < n; i++) {
		if (vec[i] != pre[i]) {
			break;
		}
	}
	// 如果初始序列是先序序列，输出它的后序序列
	if (i == n) {
		printf("YES\n");
		postorder1(root);
		printf("%d", post[0]);
		for (int j = 1; j < n; j++) {
			printf(" %d", post[j]);
		}
		return 0;
	}
	// 判断初始序列是否是先序序列的镜像序列
	pre.clear();
	preorder2(root);
	for (i = 0; i < n; i++) {
		if (vec[i] != pre[i]) {
			break;
		}
	}
	// 如果初始序列是先序序列的镜像序列，输出它的后序序列的镜像序列
	if (i == n) {
		printf("YES\n");
		postorder2(root);
		printf("%d", post[0]);
		for (int j = 1; j < n; j++) {
			printf(" %d", post[j]);
		}
		return 0;
	}
	printf("NO\n");
	return 0;
}

/*
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail) {  // 进来的前序，第一个就是根节点
	if (root > tail) return;
	int i = root + 1, j = tail;
	if (!isMirror) {
		while (i <= tail && pre[root] > pre[i]) i++;
		while (j > root && pre[root] <= pre[j]) j--;
	}
	if (i - j != 1) return;
	getpost(root + 1, j);
	getpost(i, tail);
	post.push_back(pre[root]);
}

int main() {
	int n;
	scanf("%d", &n);
	pre.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &pre[i]);  // 先假设输入的序列是BST的前序遍历
	getpost(0, n - 1);  // 将前序遍历转换为后序遍历
	return 0;
}
*/