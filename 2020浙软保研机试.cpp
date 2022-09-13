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
# include <map>
# include <cmath>
using namespace std;

int n1, n2, n3;
vector<int> v1, v2, v3;

int main() {
    scanf("%d %d %d", &n1, &n2, &n3);
    v1.resize(n1); v2.resize(n2); v3.resize(n3);
    for (int i = 0; i < n1; i++) scanf("%d", &v1[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &v2[i]);
    for (int i = 0; i < n3; i++) scanf("%d", &v3[i]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    int a, b, c, d, mind = 999999999, ma, mb, mc;
    int flag = 0, pred;
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            for (int k = n3 - 1; k >= 0; k--) {
                flag = 0;
                a = v1[i];
                b = v2[j];
                c = v3[k];
                d = abs(a - b) + abs(a - c) + abs(b - c);
                if (d < mind) {
                    ma = a; mb = b; mc = c;
                    mind = d;
                    flag = 1;
                }
                if (flag == 0 && pred < d) {
                    break;
                }
                pred = d;
            }
        }
    }
    printf("MinD(%d, %d, %d) = %d", ma, mb, mc, mind);
    return 0;
}

/*
struct node {
    int sumScore;
    int id;
    int num;
    vector<int> students;
};

bool cmp(node a, node b) {
    if (a.sumScore != b.sumScore) return a.sumScore > b.sumScore;
    // else if (a.students.size() != b.students.size()) return a.students.size() < b.students.size();
    else if (a.num != b.num) return a.num < b.num;
    else return a.id < b.id;
}

const int maxn = 10010;
bool visit[maxn];
vector<int> pre[maxn];
node school[maxn];
int n, cnt;
int scores[maxn];
vector<int> students;

void dfs(int u) {
    visit[u] = true;
    school[cnt].sumScore += scores[u];
    school[cnt].students.push_back(u);
    school[cnt].num++;
    if (u < school[cnt].id) school[cnt].id = u;
    for (int i = 0; i < pre[u].size(); i++) {
        int v = pre[u][i];
        if (visit[v] == false) {
            dfs(v);
        }
    }
}

int main() {
    scanf("%d", &n);
    int tstudent, m, tscore, temp;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tstudent, &m);
        students.push_back(tstudent);
        for (int j = 0; j < m; j++) {
            scanf("%d", &temp);
            pre[tstudent].push_back(temp);
            pre[temp].push_back(tstudent);
        }
        scanf("%d", &tscore);
        scores[tstudent] = tscore;
    }
    for (int i = 0; i < students.size(); i++) {
        if (visit[students[i]] == false) {
            school[cnt].id = 9999999;
            school[cnt].students.clear();
            school[cnt].num = 0;
            school[cnt].sumScore = 0;
            dfs(students[i]);
            cnt++;
        }
    }
    printf("%d\n", cnt);
    sort(school, school + cnt, cmp);
    for (int i = 0; i < cnt; i++) {
        if (i != 0) printf("\n");
        printf("%04d %d %d", school[i].id, school[i].students.size(), school[i].sumScore);
    }

    return 0;
}*/

/*
int n, d, maxnum = 0, maxrest = 0;
int items[100010], coupons[100010];
map<int, int> price;

int main() {
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) scanf("%d", items[i]);
    for (int i = 0; i < n; i++) scanf("%d", coupons[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t = items[i] - coupons[j];
            price[t]++;
        }
    }
    int rest = d;
    for (auto it : price) {
        int sum = it.second;
        int p = it.first;
        if (rest >= sum * p) {
            maxnum += sum;
            rest -= sum * p;
            continue;
        }
        else if (rest >= p) {
            int cnt = rest / p;
            maxnum += cnt;
            rest = rest % p;
            continue;
        }
        break;
    }
    printf("%d %d", maxnum, rest);
    return 0;
}
*/