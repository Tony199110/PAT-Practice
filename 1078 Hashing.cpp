# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <set>
# include <stack>
# include <algorithm>
# include <string>
# include <cstring>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

int msize, n, hashTable[10010];
bool isprime(int num) {
	if (num == 1) return false;
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0) return false;
	return true;
}
void insert(int key) {  // 建立hash表，每次插入一个
	for (int step = 0; step < msize; step++) {
		int index = (key + step * step) % msize;  // 二次探查法
		if (hashTable[index] == 0) {
			hashTable[index] = 1;
			cout << index % msize;  // 实际存储在数组的位置
			return;
		}
	}
	cout << '-';  // 二次探查冲突
}

int main() {
	scanf("%d %d", &msize, &n);
	while (!isprime(msize)) msize++;  // 得到Tsize
	for (int i = 0; i < n; i++) {
		int key;
		scanf("%d", &key);
		if (i != 0) cout << ' ';
		insert(key);
	}
	return 0;
}
