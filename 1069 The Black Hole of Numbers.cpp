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

bool cmp1(char a, char b) {
	return a > b;  // sortĬ�����������������������
}
int main() {
	string s;
	cin >> s;
	s.insert(0, 4 - s.length(), '0');
	do {  // Ϊ�˴���һ��ʼ����6174�����
		string a = s, b = s;
		sort(a.begin(), a.end(), cmp1);
		sort(b.begin(), b.end());
		int result = stoi(a) - stoi(b);
		s = to_string(result);
		s.insert(0, 4 - s.length(), '0');
		cout << a << " - " << b << " = " << s << endl;
	} while (s != "6174" && s != "0000");
	return 0;
}

