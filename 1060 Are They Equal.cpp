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

string s1, s2, a1, a2;

string translate(int n, string s) {  // ������һ����ת��Ϊ����nλ��Ч���ֵĿ�ѧ��������ʾ
	int len = s.size(), i = 0, count = 0;
	string ans;
	while (i < len && s[i] == '0') {  // Խ��ǰ����
		i++;
	}
	if (s[i] == '.') {  // ��s��С��1�ĸ�������0.xxx����
		i++;  // Խ��С����
		while (s[i] == '0') {  // Խ��С������ǰ����
			count--;  // count��ָ��
			i++;
		}
		bool judge = false;
		while (ans.size() < n && i < len) {
			ans.push_back(s[i]);
			judge = true;
			i++;
		}
		while (ans.size() < n) ans.push_back('0');
		if (!judge) count = 0;  // û�з�0�������Ǿ���0.0��������ָ��count��û����
	}
	else {  // ����1����
		for (int j = i; s[j] != '.' && j < len; j++) count++;  // ��ͳ��С����ǰ��ķ������ֵĸ�������ָ��
		while (s[i] != '.' && ans.size() < n && i < len) {
			ans.push_back(s[i]);
			i++;
		}
		if (ans.size() < n) i++;  // �����С���㣬��Խ�������û��С���㣬����һ�в��ܽ�ȥ��񶼲�������
		while (i < len && ans.size() < n) {  // ��ȥ���ֻ������С��������
			ans.push_back(s[i]);  // ��С����������Ҳ�Ž���
			i++;
		}
		while (ans.size() < n) ans.push_back('0');  // ������������������ǲ���Ҫ�����Чλ����������0
	}
	ans += ("*10^" + to_string(count));
	return ans;
}

int main() {
	string s1, s2;
	int n, flag = 0;
	cin >> n >> s1 >> s2;
	a1 = translate(n, s1);
	a2 = translate(n, s2);
	if (a1 == a2) cout << "YES 0." << a1;
	else cout << "NO 0." << a1 << " 0." << a2;
	return 0;
}
