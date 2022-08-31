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

struct node {
	int val;
	struct node* left, * right;
};
node* leftLeftRotate(node* root) {  // LL单旋转
	node* t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}
node* rightRightRotate(node* root) {  // RR单旋转
	node* t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}
node* leftRightRotate(node* root) {  // LR旋转，先在左子树RR单旋转，再在根节点LL单旋转
	root->left = rightRightRotate(root->left);
	return leftLeftRotate(root);
}
node* rightLeftRotate(node* root) {  // RL旋转，先在右子树LL单旋转，再在根节点RR单旋转
	root->right = leftLeftRotate(root->right);
	return rightRightRotate(root);
}
int getHeight(node* root) {
	if (root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node* insert(node* root, int val) {
	if (root == NULL) {
		root = new node();
		root->val = val;
		root->left = root->right = NULL;
	}
	else if (val < root->val) {  // 比当前节点小，则插入左边
		root->left = insert(root->left, val);
		if (getHeight(root->left) - getHeight(root->right) == 2) {
			if (val < root->left->val)  // 比左孩子的值要小，说明是LL的情况
				root = leftLeftRotate(root);
			else  // LR的情况
				root = leftRightRotate(root);
		}
	}
	else {  // 比当前节点大或相等，则插入右边
		root->right = insert(root->right, val);
		if (getHeight(root->right) - getHeight(root->left) == 2) {
			if (val < root->right->val)  // 比右孩子的值要小，说明是RL的情况
				root = rightLeftRotate(root);
			else  // RR的情况
				root = rightRightRotate(root);
		}
	}
	return root;
}

int main() {
	int n, val;
	scanf("%d", &n);
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		root = insert(root, val);
	}
	printf("%d", root->val);
	return 0;
}
