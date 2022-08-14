# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
using namespace std;

int main() {
	int n, minn = INT32_MAX, maxn = INT32_MIN;
	scanf("%d", &n);
	string unlocked, locked;
	for (int i = 0; i < n; i++) {
		string ID;
		cin >> ID;
		int h1, m1, s1, h2, m2, s2;
		// 格式化输入时，如时间，使用scanf是非常好的选择
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
		int tempIn = h1 * 3600 + m1 * 60 + s1;
		int tempOut = h2 * 3600 + m2 * 60 + s2;
		if (tempIn < minn) {
			minn = tempIn;
			unlocked = ID;
		}
		if (tempOut > maxn) {
			maxn = tempOut;
			locked = ID;
		}
	}
	cout << unlocked << " " << locked;
	return 0;
}