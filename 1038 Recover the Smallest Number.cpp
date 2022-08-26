# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <set>
# include <algorithm>
# include <string>
# include <cstring>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

bool cmp1(string a, string b) {
	return a + b < b + a;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<string> v;
	string tmps, ans;
	for (int i = 0; i < n; i++) {
		cin >> tmps;
		v.push_back(tmps);
	}
	sort(v.begin(), v.end(), cmp1);
	for (int i = 0; i < n; i++) 
		ans += v[i];
	while (ans.length() != 0 && ans[0] == '0')  // 去除前导0
		ans.erase(ans.begin());
	if (ans.length() == 0)  // 有可能去除前导0后空了，就直接输出一个0
		cout << 0;
	else
		cout << ans;
	return 0;
}