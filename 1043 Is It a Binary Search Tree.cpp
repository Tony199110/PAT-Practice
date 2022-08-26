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

vector<int> pre, post, vec;  // ���������������򡢺��򡢳�ʼ����
struct node {
	int data;
	struct node* left, * right;
};

struct node* root = NULL;  // ��ʼ�����ڵ��ַΪNULL
node* insert(node* root, int data) {  // �βηֱ��ǵ�ǰ���ĸ�����ַ��Ҫ����Ľڵ�ֵ
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
		pre.push_back(root->data);  // ��
		preorder1(root->left);  // ��
		preorder1(root->right);  // ��
	}
}
void postorder1(node* root) {
	if (root != NULL) {
		postorder1(root->left);  // ��
		postorder1(root->right);  // ��
		post.push_back(root->data);  // ��
	}
}
void preorder2(node* root) {  // ǰ�����еľ�������
	if (root != NULL) {
		pre.push_back(root->data);  // ��
		preorder2(root->right);  // ��
		preorder2(root->left);  // ��
	}
}
void postorder2(node* root) {
	if (root != NULL) {
		postorder2(root->right);  // ��
		postorder2(root->left);  // ��
		post.push_back(root->data);  // ��
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		vec.push_back(temp);
		root = insert(root, temp);  //������һ�ö���������
	}
	// �жϳ�ʼ�����Ƿ�����������
	pre.clear();
	preorder1(root);
	int i = 0;
	for (i = 0; i < n; i++) {
		if (vec[i] != pre[i]) {
			break;
		}
	}
	// �����ʼ�������������У�������ĺ�������
	if (i == n) {
		printf("YES\n");
		postorder1(root);
		printf("%d", post[0]);
		for (int j = 1; j < n; j++) {
			printf(" %d", post[j]);
		}
		return 0;
	}
	// �жϳ�ʼ�����Ƿ����������еľ�������
	pre.clear();
	preorder2(root);
	for (i = 0; i < n; i++) {
		if (vec[i] != pre[i]) {
			break;
		}
	}
	// �����ʼ�������������еľ������У�������ĺ������еľ�������
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
void getpost(int root, int tail) {  // ������ǰ�򣬵�һ�����Ǹ��ڵ�
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
		scanf("%d", &pre[i]);  // �ȼ��������������BST��ǰ�����
	getpost(0, n - 1);  // ��ǰ�����ת��Ϊ�������
	return 0;
}
*/