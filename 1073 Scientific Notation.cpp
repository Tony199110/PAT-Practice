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
	string s;
	cin >> s;
	int i = 0;
	while (s[i] != 'E') i++;  // 此时，s[i]就是E
	string t = s.substr(1, i - 1);  // 截取中间的数出来
	int n = stoi(s.substr(i + 1));  // 截取出指数
	if (s[0] == '-') cout << '-';
	if (n < 0) {
		cout << "0.";
		for (int j = 0; j < abs(n) - 1; j++) cout << '0';
		for (int j = 0; j < t.length(); j++)
			if (t[j] != '.') cout << t[j];
	}
	else {  // 大于0稍微麻烦一点
		cout << t[0];  // 第一个字符直接输出，第二个字符是 .
		int len2 = t.length() - 2;  // 小数点后的数字串的长度，即小数部分的长度
		if (len2 > n) {  // 还带小数点
			for (int j = 0; j < n; j++) cout << t[j + 2];
			cout << '.';
			for (int j = 0; j < len2 - n; j++) cout << t[j + 2 + n];
		}
		else if (len2 <= n) {  // 没有小数点了
			for (int j = 0; j < len2; j++) cout << t[j + 2];
			for (int j = 0; j < n - len2; j++) cout << '0';
		}
	}
	return 0;
}

