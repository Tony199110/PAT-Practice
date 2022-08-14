# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <iomanip>
using namespace std;

int main() {
	int n1, n2, a, cnt = 0;
	float b, arr[1001] = { 0.0 }, ans[2001] = { 0.0 };
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%d %f", &a, &b);
		arr[a] = b;
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d %f", &a, &b);
		for (int j = 0; j < 1001; j++) {
			ans[j + a] += arr[j] * b;  // 相乘得到的项次数更高，故+a
		}
	}
	for (int i = 2000; i >= 0; i--) {
		if (ans[i] != 0.0) cnt++;
	}
	cout << cnt;
	for (int i = 2000; i >= 0; i--) {
		if (ans[i] != 0.0) {
			// cout << " " << i << " " << fixed << setprecision(1) << ans[i];
			printf(" %d %.1f", i, ans[i]);
		}
	}
	return 0;
}