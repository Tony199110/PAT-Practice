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
	while (s[i] != 'E') i++;  // ��ʱ��s[i]����E
	string t = s.substr(1, i - 1);  // ��ȡ�м��������
	int n = stoi(s.substr(i + 1));  // ��ȡ��ָ��
	if (s[0] == '-') cout << '-';
	if (n < 0) {
		cout << "0.";
		for (int j = 0; j < abs(n) - 1; j++) cout << '0';
		for (int j = 0; j < t.length(); j++)
			if (t[j] != '.') cout << t[j];
	}
	else {  // ����0��΢�鷳һ��
		cout << t[0];  // ��һ���ַ�ֱ��������ڶ����ַ��� .
		int len2 = t.length() - 2;  // С���������ִ��ĳ��ȣ���С�����ֵĳ���
		if (len2 > n) {  // ����С����
			for (int j = 0; j < n; j++) cout << t[j + 2];
			cout << '.';
			for (int j = 0; j < len2 - n; j++) cout << t[j + 2 + n];
		}
		else if (len2 <= n) {  // û��С������
			for (int j = 0; j < len2; j++) cout << t[j + 2];
			for (int j = 0; j < n - len2; j++) cout << '0';
		}
	}
	return 0;
}

