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

char s1[10005], s2[10005];
int main() {
	cin.getline(s1, 10005);
	cin.getline(s2, 10005);
	int len1 = strlen(s1), len2 = strlen(s2);
	bool flag[256] = { false };
	for (int i = 0; i < len2; i++) {
		flag[s2[i]] = true;  // 标记需要剔除的字符
	}
	for (int i = 0; i < len1; i++) {
		if (!flag[s1[i]]) {  // 只输出不需要剔除的字符
			printf("%c", s1[i]);
		}
	}
	return 0;
}
