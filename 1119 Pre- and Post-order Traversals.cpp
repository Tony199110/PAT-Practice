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
bool Unique = true;  // ǰ��+�����п����޷��õ�һ��ȷ�����������������������������������������ʱ

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
    if (postL > postR) return NULL;  // ��ͷ��
    // �����ĺ��Ĳ���
    node* root = new node;
    root->data = post[postR];  // ��һ�����ں�����O(1)�ҳ����ڵ㣬�����һ��
    int i = inL;
    while (in[i] != post[postR] && i <= inR) i++;  // �ڶ�������������O(n)�ҵ����ڵ㣬��¼��λ�ã�֮�󣬸����伴�ɻ�����������������
    int numLeft = i - inL;  // ������������һ�����Ե�֪�������Ľڵ����������������ں����л���������ĺ����������Ȼ������Ҳͬʱ����ˣ�
    root->left = buildBiTreeWithPostIn(postL, postL + numLeft - 1, inL, i - 1);  // ȥ�ظ���һ�������������ظ��ķ�ʽ���ǵݹ�
    root->right = buildBiTreeWithPostIn(postL + numLeft, postR - 1, i + 1, inR);
    return root;
}

void preOrder(node* root) {  // ǰ���������������
    printf("%d ", root->data);  // ��
    if (root->left != NULL) preOrder(root->left);  // ������
    if (root->right != NULL) preOrder(root->right);  // ������
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
            Unique = false;  // ����Ψһ
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
        printf("%d", now->data);  // ��Ŀ��һ������now���Ӧ��
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
