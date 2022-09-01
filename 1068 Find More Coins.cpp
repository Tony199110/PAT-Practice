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
	sort(w, w + cnt, cmp1);  // �Ӵ�С����
	for (int i = 0; i < cnt; i++) {
		for (int j = m; j >= w[i]; j--) {  // �������j�ܷŵ��µ�i����Ʒ
			if (dp[j] <= dp[j - w[i]] + w[i]) {  // ������˵�i����Ʒ���Ȳ����ܻ�ø��������
				choice[i][j] = true;  // �Ǿ;����ڱ�������Ϊj��ʱ��ŵ�i����Ʒ
				dp[j] = dp[j - w[i]] + w[i];  // ���±�������ܼ�ֵ
			}
		}
	}
	if (dp[m] != m) printf("No Solution");  // ������Ϊmʱ���ܼ�ֵ������m�����򸶲������Ǯ
	else {
		vector<int> ans;
		int v = m, index = cnt - 1;
		while (v > 0) {
			if (choice[index][v] == true) {
				ans.push_back(w[index]);  // ÿ�ζ�����С��
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

