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

const int maxn = 200005;
int n1, n2, a1[maxn], a2[maxn], cnt = 0, i, j, ans;

int main() {
	scanf("%d", &n1);
	for (i = 1; i <= n1; i++) scanf("%d", &a1[i]);
	scanf("%d", &n2);
	for (i = 1; i <= n2; i++) scanf("%d", &a2[i]);
	int target = (n1 + n2 + 1) / 2;  // 中位数所在位置的下标
	i = 1, j = 1;
	while (i <= n1 && j <= n2) {
		ans = a1[i] <= a2[j] ? a1[i++] : a2[j++];  // 归并的思想
		if (++cnt == target) break;  // 找到中位数就可以溜了
	}
	if (i <= n1 && cnt < target) {  // a2遍历完了还没找到中位数
		ans = a1[i + (target - (cnt + 1))];  // i和target的单位是下标，而cnt是指针移动的位置，需要+1才能平等地参与前者的运算
	}
	else if (j <= n2 && cnt < target) {
		ans = a2[j + (target - (cnt + 1))];
	}
	printf("%d", ans);
	return 0;
}