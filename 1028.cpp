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

const int maxn = 100001;
struct node {
	int id, score;
	char name[10];
} stu[maxn];
int c;
bool cmp1(node a, node b) {
	if (c == 1) {
		return a.id < b.id;
	}
	else if (c == 2) {
		if (strcmp(a.name, b.name) == 0) { return a.id < b.id; }
		return strcmp(a.name, b.name) <= 0;
	}
	else if (c == 3) {
		if (a.score == b.score) { return a.id < b.id; }
		return a.score < b.score;
	}
}

int main() {
	int n;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d %s %d", &stu[i].id, &stu[i].name, &stu[i].score);
	}
	sort(stu, stu + n, cmp1);
	for (int i = 0; i < n; i++) {
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
	}
	return 0;
}