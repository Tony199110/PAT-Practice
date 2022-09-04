// # include <bits/stdc++.h>
# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

const int maxn = 10001;
bool e[maxn][maxn];
// vector<int> prein[maxn], preout[maxn];
vector<int> outnum, innum;
int main() {
    int n, m, tmp;
    double t;
    scanf("%d %lf", &n, &t);
    outnum.resize(n + 1);
    innum.resize(n + 1);
    fill(innum.begin(), innum.end(), 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        outnum[i] = m;
        for (int j = 1; j <= m; j++) {
            scanf("%d", &tmp);
            e[i][tmp] = 1;
            innum[tmp]++;
        }
    }
    vector<int> ol, oll;
    for (int i = 1; i <= n; i++) {
        if ((double)innum[i] / outnum[i] >= t) {
            ol.push_back(i);
        }
    }
    int maxoll = -1;
    oll.resize(ol.size());
    for (int i = 0; i < ol.size(); i++) {
        oll[i] = 0;
        for (int j = 0; j < ol.size(); j++) {
            if (e[ol[j]][ol[i]]) {
                oll[i]++;
            }
        }
        if (oll[i] > maxoll) {
            maxoll = oll[i];
        }
    }
    int cnt = 0;
    for (int i = 0; i < ol.size(); i++) {
        if (oll[i] == maxoll) {
            if (cnt == 0) printf("%d", ol[i]);
            else printf(" %d", ol[i]);
            cnt++;
        }
    }
    return 0;
}



















/* µÚÒ»Ìâ
int main() {
    int n, height;
    scanf("%d %d", &n, &height);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    int maxb = 1, index = -1;
    for (int i = n - 1; i >= 0; i--) {
        int temp = v[i], cnt = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (v[i] - v[j] <= height) {
                cnt++;
            }
            else break;
        }
        if (cnt >= maxb) {
            maxb = cnt;
            index = v[i];
        }
    }


    printf("%d %d", index - height, maxb);
    return 0;
}*/