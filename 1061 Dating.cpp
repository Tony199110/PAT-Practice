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
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	char t[3];
	int i = 0, j = 0;
	while (i < a.length() && i < b.length()) {
		if (a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G') {
			t[0] = a[i];
			break;
		}
		i++;
	}
	i++;
	while (i < a.length() && i < b.length()) {
		if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))) {
			t[1] = a[i];
			break;
		}
		i++;
	}
	while (j < c.length() && j < d.length()) {
		if (c[j] == d[j] && isalpha(c[j])) {
			t[2] = j;
			break;
		}
		j++;
	}
	string week[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	cout << week[t[0] - 'A'] << ' ';
	int mm = isdigit(t[1]) ? t[1] - '0' : t[1] - 'A' + 10;
	printf("%02d:%02d", mm, t[2]);
	return 0;
}
