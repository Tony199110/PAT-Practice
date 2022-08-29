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

# define lowbit(i) ((i) & (-i))
const int maxn = 100010;
int c[maxn];  // 树状数组；哈希散列，下标是输入的数，数组里对应存的是数的个数
stack<int> s;
void update(int x, int v) {  // 更新树状数组c，x是要修改的数，v是1代表加入了x，v是-1代表除去了x
	for (int i = x; i < maxn; i += lowbit(i)) {  // 用这个for去遍历数组后，自然就形成了一个树状数组
		c[i] += v;
	}
}
int getsum(int x) {  // 统计小于等于x的数的个数
	int sum = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {  // 这个树状数组的好处就是可以“跳着”去找相差很大的数
		sum += c[i];
	}
	return sum;
}
void PeekMedian() {
	int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;  // 去找这第k小的数，而比一半数小的数就是中位数
	while (left < right) {  // 二分查找
		mid = (left + right) / 2;
		if (getsum(mid) >= k)
			right = mid;
		else
			left = mid + 1;
	}
	printf("%d\n", left);
	return;
	/*  // 用for直接遍历不行，会超时
	for (int i = 1; i < maxn; i++) {
		if (getsum(i) == k) {
			printf("%d\n", i);
			return;
		}
	}*/
}

int main() {
	int n, temp;
	scanf("%d", &n);
	char str[15];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		if (str[1] == 'u') {  // push key
			scanf("%d", &temp);
			s.push(temp);
			update(temp, 1);  // 树状数组增加一个数
		}
		else if (str[1] == 'o') {  // pop
			if (s.empty()) {
				printf("Invalid\n");
			}
			else {
				update(s.top(), -1);  // 树状数组减少一个数
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else {  // peekMedian
			if (s.empty()) {
				printf("Invalid\n");
			}
			else {
				PeekMedian();
			}
		}
	}
	return 0;
}
