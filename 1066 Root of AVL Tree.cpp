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
node* leftLeftRotate(node* root) {  // LL����ת
	node* t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}
node* rightRightRotate(node* root) {  // RR����ת
	node* t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}
node* leftRightRotate(node* root) {  // LR��ת������������RR����ת�����ڸ��ڵ�LL����ת
	root->left = rightRightRotate(root->left);
	return leftLeftRotate(root);
}
node* rightLeftRotate(node* root) {  // RL��ת������������LL����ת�����ڸ��ڵ�RR����ת
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
	else if (val < root->val) {  // �ȵ�ǰ�ڵ�С����������
		root->left = insert(root->left, val);
		if (getHeight(root->left) - getHeight(root->right) == 2) {
			if (val < root->left->val)  // �����ӵ�ֵҪС��˵����LL�����
				root = leftLeftRotate(root);
			else  // LR�����
				root = leftRightRotate(root);
		}
	}
	else {  // �ȵ�ǰ�ڵ�����ȣ�������ұ�
		root->right = insert(root->right, val);
		if (getHeight(root->right) - getHeight(root->left) == 2) {
			if (val < root->right->val)  // ���Һ��ӵ�ֵҪС��˵����RL�����
				root = rightLeftRotate(root);
			else  // RR�����
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
