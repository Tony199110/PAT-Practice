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

int main() {
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++) {
		bool flag = false;
		stack<int> s;
		vector<int> v(n + 1);
		for (int j = 1; j <= n; j++)
			scanf("%d", &v[j]);
		int current = 1;  // 用于标记刚输入的可能序列的位置
		for (int j = 1; j <= n; j++) {
			s.push(j);
			if (s.size() > m) break;
			while (!s.empty() && s.top() == v[current]) {
				s.pop();  // 栈顶与输出序列相等，则弹出栈顶
				current++;  // 去判断下一个位置
			}
		}
		if (current == n + 1) flag = true;
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
