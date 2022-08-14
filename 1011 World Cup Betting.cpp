# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
using namespace std;

int main() {
	char c[4] = { "WTL" };
	float ans = 1.0;
	for (int i = 0; i < 3; i++) {
		float maxvalue = 0.0;
		int maxchar = 0;
		for (int j = 0; j < 3; j++) {
			float temp;
			scanf("%f", &temp);
			if (maxvalue <= temp) { // 找最大值和其对应的下标
				maxvalue = temp;
				maxchar = j;
			}
		}
		ans = ans * maxvalue;
		printf("%c ", c[maxchar]);
	}
	printf("%.2f", (ans * 0.65 - 1) * 2);
	return 0;
}