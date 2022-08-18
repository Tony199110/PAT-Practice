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

int main() {
	char c[14] = {"0123456789ABC"};
	printf("#");
	for (int i = 0; i < 3; i++) {
		int num;
		scanf("%d", &num);
		printf("%c%c", c[num / 13], c[num % 13]);
	}
	return 0;
}