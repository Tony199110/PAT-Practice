# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

struct node {
	int data, next;
}list[100010];
vector<int> v;
int main() {
	int start, n, k;  scanf("%d %d %d", &start, &n, &k);
	int a, b, c;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		list[a].data = b;
		list[a].next = c;
	}
	for (int i = start; i != -1; i = list[i].next) {
		v.push_back(i);
	}
	int i = 0;
	for (i = 0; i + k <= v.size(); i += k) {
		reverse(v.begin() + i, v.begin() + i + k);
	}
	if (v.size() % k != 0) reverse(v.begin() + i, v.end());
	reverse(v.begin(), v.end());
	for (i = 0; i < v.size() - 1; i++) {
		printf("%05d %d %05d\n", v[i], list[v[i]].data, v[i + 1]);
	}
	printf("%05d %d -1", v[i], list[v[i]].data);
	return 0;
}