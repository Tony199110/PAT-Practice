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

string translate(int n, string s) {  // 将任意一个数转换为保留n位有效数字的科学计数法表示
	int len = s.size(), i = 0, count = 0;
	string ans;
	while (i < len && s[i] == '0') {  // 越过前导零
		i++;
	}
	if (s[i] == '.') {  // 若s是小于1的浮点数，0.xxx这种
		i++;  // 越过小数点
		while (s[i] == '0') {  // 越过小数点后的前导零
			count--;  // count是指数
			i++;
		}
		bool judge = false;
		while (ans.size() < n && i < len) {
			ans.push_back(s[i]);
			judge = true;
			i++;
		}
		while (ans.size() < n) ans.push_back('0');
		if (!judge) count = 0;  // 没有非0的数，那就是0.0这种数，指数count就没用了
	}
	else {  // 大于1的数
		for (int j = i; s[j] != '.' && j < len; j++) count++;  // 先统计小数点前面的非零数字的个数，即指数
		while (s[i] != '.' && ans.size() < n && i < len) {
			ans.push_back(s[i]);
			i++;
		}
		if (ans.size() < n) i++;  // 如果有小数点，则越过；如果没有小数点，那这一行不管进去与否都不起作用
		while (i < len && ans.size() < n) {  // 进去这里，只能是有小数点的情况
			ans.push_back(s[i]);  // 把小数点后面的数也放进来
			i++;
		}
		while (ans.size() < n) ans.push_back('0');  // 遍历完了这个数，还是不够要求的有效位数，就往后补0
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
