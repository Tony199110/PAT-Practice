# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <iomanip>
using namespace std;

int main() {
	int n, going, now = 0, sum = 0;
	cin >> n;
	// while (cin >> going) {
	for (int i = 0; i < n; i++) {
		cin >> going;
		if (going > now)
			sum = sum + 6 * (going - now);
		else
			sum = sum + 4 * (now - going);
		now = going;
		sum += 5;
	}
	cout << sum;
	return 0;
}