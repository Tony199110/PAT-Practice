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

vector<int> v;
int cnt = 0;
void swap(int x) {
	int temp = v[0];
	v[0] = v[x];
	v[x] = temp;
	cnt++;
}
int main() {
	int n, temp, i = 0;
	bool sorted = false;
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		v[temp] = i;  // 记录每个元素的位置，某个元素temp在第i个位置
	}
	while (!sorted) {
		if (v[0] == 0) {  // 若0提前回到了自己的位置，那就要找一个未排序的数交换
			while (++i < n) {
				if (v[i] != i) {
					swap(i);  // 将i与0交换
					break;
				}
			}
			if (i == n) sorted = true;  // 找不到未排序的，那就结束了
		}
		else {  // 正常情况
			swap(v[0]);  // 将 0现在所在位置的下标指向的数 跟 0 进行交换
		}
	}
	printf("%d", cnt);
	return 0;
}

