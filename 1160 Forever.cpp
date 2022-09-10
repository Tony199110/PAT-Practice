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
    int n, A;  // 各数位之和、目标数字
};
int n, m, N, k;
vector<node> ans;

bool cmp(node a, node b) {
    if (a.n != b.n) return a.n < b.n;
    else return a.A < b.A;
}

bool isPrime(int n) {
    if (n <= 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int digit_sum(int A) {
    int sum = 0;
    while (A) {
        sum += A % 10;
        A /= 10;
    }
    return sum;
}

void dfs(int A, int sum, int rest_K) {
    if (rest_K == 0) {
        if (sum == m) {
            int n = digit_sum(A + 1);
            if (isPrime(gcd(m, n)))
                ans.push_back({ n, A });
        }
    }
    else if (rest_K > 0) {
        for (int i = 0; i <= 9; i++) {
            if (sum + i + (rest_K-1)*9 >= m && sum + i <= m)  // 太小或太大就剪枝掉
                dfs(A * 10 + i, sum + i, rest_K - 1);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int x = 1; x <= N; x++) {
        ans.clear();
        printf("Case %d\n", x);
        scanf("%d %d", &k, &m);
        
        for (int i = 1; i <= 9; i++)
            dfs(i, i, k - 1);  // 目标数、当前数位和、剩余k位
        
        if (ans.empty()) {
            printf("No Solution\n");
            continue;
        }
        sort(ans.begin(), ans.end(), cmp);
        for (int i = 0; i < ans.size(); i++)
            printf("%d %d\n", ans[i].n, ans[i].A);
    }
    return 0;
}

