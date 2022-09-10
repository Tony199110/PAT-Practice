// # include <bits/stdc++.h>
# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;

struct node {
    double price;
    vector<int> child;
};

vector<node> v;
double ans = 0.0, p, r;
int cnt = 0;
int minh = 99999999;

void dfs(int index, int depth) {
    if (v[index].child.size() == 0 && depth == minh) {
        ans = pow(1 + r * 0.01, depth);
        cnt++;
    }
    for (int i = 0; i < v[index].child.size(); i++) {
        dfs(v[index].child[i], depth + 1);
    }
}

void getHeight(int index, int depth) {
    if (v[index].child.size() == 0) {
        if (depth < minh) minh = depth;
        return;
    }
    for (int i = 0; i < v[index].child.size(); i++) {
        getHeight(v[index].child[i], depth + 1);
    }
}

int main() {
    int n, k, tmp;
    scanf("%d %lf %lf", &n, &p, &r);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &tmp);
            if (tmp != 0)
                v[i].child.push_back(tmp);
        }
    }
    getHeight(0, 0);
    dfs(0, 0);
    printf("%.4lf %d", ans * p, cnt);
}
