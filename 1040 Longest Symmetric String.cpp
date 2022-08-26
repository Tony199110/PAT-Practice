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
// ��ʱ4ms���ڴ�0.5MB
int main() {
	string str;
	getline(cin, str);
	int len = str.length(), maxlen = 1;
	for (int i = 0; i < len - 1; i++) {
		int mid = i, range = 1, tmplen = 1;
		while (mid - range >= 0 && mid + range < len) {  // �����Գ��Ӵ�
			if (str[mid - range] == str[mid + range]) {
				tmplen += 2;
				range++;
				if (tmplen > maxlen) {
					maxlen = tmplen;
				}
			}
			else break;
		}
		range = 1, tmplen = 0;
		while (mid - range + 1 >= 0 && mid + range < len) {  // ż���Գ��Ӵ�
			if (str[mid - range + 1] == str[mid + range]) {
				tmplen += 2;
				range++;
				if (tmplen > maxlen) {
					maxlen = tmplen;
				}
			}
			else break;
		}
	}
	printf("%d", maxlen);
	return 0;
}

/*  // ��ʱ6ms���ڴ�4MB
int dp[1010][1010];
int main() {
	string s;
	getline(cin, s);
	int len = s.length(), ans = 1;
	for (int i = 0; i < len; i++) {  // �ȳ�ʼ���߽�ֵ
		dp[i][i] = 1;
		if (i < len - 1 && s[i] == s[i + 1]) {
			dp[i][i + 1] = 1;
			ans = 2;
		}
	}
	for (int L = 3; L <= len; L++) {  // �ַ����ĳ���
		for (int i = 0; i + L - 1 < len; i++) {  // �Ӵ��ĳ�ʼλ��
			int j = i + L - 1;  // iΪ�Ӵ���߽磬jΪ�Ӵ��ұ߽�
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	printf("%d", ans);
	return 0;
}  */
