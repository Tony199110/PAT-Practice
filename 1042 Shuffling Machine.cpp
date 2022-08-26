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
	int cnt;
	scanf("%d", &cnt);
	int start[55], end[55], scan[55];
	for (int i = 1; i < 55; i++) {
		scanf("%d", &scan[i]);
		end[i] = i;  // 用1到54代表54张卡牌
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j < 55; j++) {
			start[j] = end[j];  
		}
		for (int j = 1; j < 55; j++) {
			end[scan[j]] = start[j];  
		}
	}
	char c[6] = { "SHCDJ" };
	for (int i = 1; i < 55; i++) {
		end[i]--;
		printf("%c%d", c[end[i] / 13], end[i] % 13 + 1);
		if (i != 54) printf(" ");
	}
	return 0;
}