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

int dp[110], w[10010];
bool choice[10010][110];
int cmp1(int a, int b) {
	return a > b;
}

int main() {
	int n, m, temp, cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		if (temp <= m) {
			w[cnt] = temp;
			cnt++;
		}
	}
	sort(w, w + cnt, cmp1);  // 从大到小排序
	for (int i = 0; i < cnt; i++) {
		for (int j = m; j >= w[i]; j--) {  // 最大容量j能放的下第i个物品
			if (dp[j] <= dp[j - w[i]] + w[i]) {  // 如果放了第i个物品，比不放能获得更大的收益
				choice[i][j] = true;  // 那就决定在背包容量为j的时候放第i个物品
				dp[j] = dp[j - w[i]] + w[i];  // 更新背包最大总价值
			}
		}
	}
	if (dp[m] != m) printf("No Solution");  // 当容量为m时，总价值必须是m，否则付不了这比钱
	else {
		vector<int> ans;
		int v = m, index = cnt - 1;
		while (v > 0) {
			if (choice[index][v] == true) {
				ans.push_back(w[index]);  // 每次都拿最小的
				v -= w[index];
			}
			index--;
		}
		printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); i++)
			printf(" %d", ans[i]);
	}
	return 0;
}

