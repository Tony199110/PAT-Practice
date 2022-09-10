// # include <bits/stdc++.h>
# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;

struct node {
    int data;
    node* left, * right;
};

const int maxn = 1010;
int in[maxn], post[maxn], pre[maxn];
vector<int> ans;
bool Unique = true;  // 前序+后序有可能无法得到一棵确定的树，这种情况出现在左子树或右子树不存在时

node* buildBiTreeWithPreIn(int preL, int preR, int inL, int inR) {
    if (preL > preR) return NULL;
    node* root = new node;
    root->data = pre[preL];
    int i = inL;
    while (in[i] != pre[preL] && i <= inR) i++;
    int numLeft = i - inL;
    root->left = buildBiTreeWithPreIn(preL + 1, preL + numLeft, inL, inL + i - 1);
    root->right = buildBiTreeWithPreIn(preL + numLeft + 1, preR, inL + i + 1, inR);
    return root;
}

void postOrder(node* root) {
    if (root->left != NULL) postOrder(root->left);
    if (root->right != NULL) postOrder(root->right);
    printf("%d ", root->data);
}

node* buildBiTreeWithPostIn(int postL, int postR, int inL, int inR) {
    if (postL > postR) return NULL;  // 到头了
    // 建树的核心部分
    node* root = new node;
    root->data = post[postR];  // 第一步，在后序中O(1)找出根节点，即最后一个
    int i = inL;
    while (in[i] != post[postR] && i <= inR) i++;  // 第二步，在中序中O(n)找到根节点，记录其位置；之后，根据其即可获得左子树的中序遍历
    int numLeft = i - inL;  // 第三步，由上一步可以得知左子树的节点个数，根据其可以在后序中获得左子树的后序遍历（当然左子树也同时获得了）
    root->left = buildBiTreeWithPostIn(postL, postL + numLeft - 1, inL, i - 1);  // 去重复第一、二、三步，重复的方式就是递归
    root->right = buildBiTreeWithPostIn(postL + numLeft, postR - 1, i + 1, inR);
    return root;
}

void preOrder(node* root) {  // 前序遍历，即根左右
    printf("%d ", root->data);  // 根
    if (root->left != NULL) preOrder(root->left);  // 左子树
    if (root->right != NULL) preOrder(root->right);  // 右子树
}

node* buildBiTreeWithPrePost(int preL, int preR, int postL, int postR) {
    if (preL == preR) {
        node* root = new node;
        root->data = pre[preL];
        root->left = root->right = NULL;
        return root;
    }
    if (pre[preL] == post[postR]) {
        node* root = new node;
        root->data = post[postR];
        int i = preL;
        while (pre[i] != post[postR - 1] && i <= preR) i++;
        int numLeft = i - preL - 1;
        if (numLeft <= 0) {
            Unique = false;  // 树不唯一
            root->left = NULL;
        }
        else root->left = buildBiTreeWithPrePost(preL + 1, i - 1, postL, postL + numLeft - 1);
        root->right = buildBiTreeWithPrePost(i, preR, postL + numLeft, postR - 1);
        return root;
    }
    return NULL;
}

void inOrder(node* root) {
    if (root->left != NULL) inOrder(root->left);
    // printf("%d ", root->data);
    ans.push_back(root->data);
    if (root->right != NULL) inOrder(root->right);
}

void levelOrder(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        printf("%d", now->data);  // 题目不一样，用now随机应变
        if (root->left != NULL) q.push(root->left);
        if (root->right != NULL) q.push(root->right);
    }
}

int getHeight(node* root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    return l > r ? l + 1 : r + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    // node* root = buildBiTreeWithPostIn(0, n - 1, 0, n - 1);
    // preOrder(root);
    // node* root = buildBiTreeWithPreIn(0, n - 1, 0, n - 1);
    // postOrder(root);
    node* root = buildBiTreeWithPrePost(0, n - 1, 0, n - 1);
    if (Unique) printf("Yes\n");
    else printf("No\n");
    inOrder(root);
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
    printf("\n");
    return 0;
}
