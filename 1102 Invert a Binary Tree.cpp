// # include <bits/stdc++.h>
# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
# include <set>
# include <cstring>
# include <cstdio>
# include <string>
using namespace std;

struct NODE {
    int left, right;
};

const int maxn = 20;
int n;
NODE nodes[maxn];
vector<int> level, in;
bool exist[maxn];

void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        level.push_back(now);
        if (nodes[now].left != -1) q.push(nodes[now].left);
        if (nodes[now].right != -1) q.push(nodes[now].right);
    }
}

void inOrder(int root) {
    if (nodes[root].left != -1) inOrder(nodes[root].left);
    in.push_back(root);
    if (nodes[root].right != -1) inOrder(nodes[root].right);
}

int main() {
    scanf("%d\n", &n);
    string c1, c2;
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> c1 >> c2;
        if (c1 == "-") nodes[i].right = -1;
        else {
            nodes[i].right = stoi(c1);
            st.insert(stoi(c1));
            exist[stoi(c1)] = true;
        }
        if (c2 == "-") nodes[i].left = -1;
        else {
            nodes[i].left = stoi(c2);
            st.insert(stoi(c2));
            exist[stoi(c2)] = true;
        }
    }
    /*
    int root = -1, i = 0;
    for (auto it = st.begin(); it != st.end(); it++){
        if (i != *it){
            root = i;
            break;
        }
        i++;
    }*/
    int root = 0;
    while (exist[root]) root++;
    levelOrder(root);
    inOrder(root);
    for (int i = 0; i < level.size() - 1; i++)
        printf("%d ", level[i]);
    printf("%d\n", level[level.size() - 1]);
    for (int i = 0; i < in.size() - 1; i++)
        printf("%d ", in[i]);
    printf("%d\n", in[in.size() - 1]);
    return 0;
}
