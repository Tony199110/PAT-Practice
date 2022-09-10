// # include <bits/stdc++.h>
# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;

struct node {
    int data, height;
    node* left, * right;
};
int maxh = 0, n1 = 0, n2 = 0;

node* insert(node* root, int data, int height) {
    if (root == NULL) {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        root->height = height;
        if (height > maxh) maxh = height;
        return root;
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data, height + 1);
        return root;
    }
    else if (data > root->data) {
        root->right = insert(root->right, data, height + 1);
        return root;
    }
}

node* buildBST(int* a, int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, a[i], 0);
    }
    return root;
}

void inOrder(node* root) {
    if (root->left != NULL) inOrder(root->left);
    if (root->height == maxh) n1++;
    if (root->height == maxh - 1) n2++;
    if (root->right != NULL) inOrder(root->right);
}

int main() {
    int n, a[1010];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    node* root = buildBST(a, n);
    inOrder(root);
    printf("%d + %d = %d", n1, n2, n1 + n2);
    return 0;
}
