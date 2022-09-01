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
	string s, t;
	getline(cin, s);
	map<string, int> m;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (isalnum(s[i])) {
			s[i] = tolower(s[i]);
			t += s[i];
		}
		if (!isalnum(s[i]) || i == len - 1) {  // 不是数字字母，或者是最后一个，说明一个单词已经被分割出来，存到t里了
			if (t.length() != 0) m[t]++;
			t = "";  // 归零一下，准备去分割下一个单词
		}
	}  // 至此，已经将字符串分割完毕并存到了map里面
	int maxn = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second > maxn) {
			t = it->first;
			maxn = it->second;
		}
	}
	cout << t << " " << maxn << endl;
	return 0;
}

