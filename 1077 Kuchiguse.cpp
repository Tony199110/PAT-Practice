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
	int n;
	scanf("%d\n", &n);
	string ans;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		//getline(cin, s);
		int lens = s.length();
		reverse(s.begin(), s.end());
		if (i == 0) ans = s;
		else {
			int lenans = ans.length();
			if (lens < lenans) swap(ans, s);  // �϶�����̵��Ǹ��ַ���Ҫ���Ķ̣��������
			int minlen = min(lens, lenans);
			for (int j = 0; j < minlen; j++) {
				if (ans[j] != s[j]) {
					ans = ans.substr(0, j);  // ��ȡ��ͬ�Ĳ���
					break;
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	if (ans.length() == 0) ans = "nai";
	cout << ans;
	return 0;
}

