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

string add(string s, string t) {  // 大整数加法函数， s = s + t
	int len = s.length(), carry = 0;
	for (int i = len - 1; i >= 0; i--) {  // 从个位开始
		s[i] = s[i] + t[i] + carry - '0';
		carry = 0;
		if (s[i] > '9') {
			s[i] = s[i] - 10;
			carry = 1;  // 有进位，由于是加法，最多进1
		}
	}
	if (carry) s = '1' + s;  // 若最高位有进位，则再添个1
	return s;
}

int main() {
	int cnt, i;
	string s;
	cin >> s >> cnt;
	for (i = 0; i < cnt; i++) {
		string t = s;
		reverse(t.begin(), t.end());
		if (s == t) break;
		s = add(s, t);
	}
	cout << s << endl << i;
	return 0;
}