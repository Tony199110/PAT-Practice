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
		if (!isalnum(s[i]) || i == len - 1) {  // ����������ĸ�����������һ����˵��һ�������Ѿ����ָ�������浽t����
			if (t.length() != 0) m[t]++;
			t = "";  // ����һ�£�׼��ȥ�ָ���һ������
		}
	}  // ���ˣ��Ѿ����ַ����ָ���ϲ��浽��map����
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

