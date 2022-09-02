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
void insert(int key) {  // ����hash��ÿ�β���һ��
	for (int step = 0; step < msize; step++) {
		int index = (key + step * step) % msize;  // ����̽�鷨
		if (hashTable[index] == 0) {
			hashTable[index] = 1;
			cout << index % msize;  // ʵ�ʴ洢�������λ��
			return;
		}
	}
	cout << '-';  // ����̽���ͻ
}

int main() {
	scanf("%d %d", &msize, &n);
	while (!isprime(msize)) msize++;  // �õ�Tsize
	for (int i = 0; i < n; i++) {
		int key;
		scanf("%d", &key);
		if (i != 0) cout << ' ';
		insert(key);
	}
	return 0;
}
