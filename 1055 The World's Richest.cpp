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

struct node {
	char name[10];
	int age, money;
};
int cmp1(node a, node b) {
	if (a.money != b.money)
		return a.money > b.money;  // 资产降序
	else if (a.age != b.age)
		return a.age < b.age;  // 年龄升序
	else
		return (strcmp(a.name, b.name) < 0);  // 字典序升序
}

int main() {
	int n, k, num, amin, amax;
	scanf("%d %d", &n, &k);
	vector<node> vt(n), v;
	vector<int> book(205, 0);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", vt[i].name, &vt[i].age, &vt[i].money);
	}
	sort(vt.begin(), vt.end(), cmp1);
	for (int i = 0; i < n; i++) {
		if (book[vt[i].age] < 100) {
			v.push_back(vt[i]);  // 只将每个年龄的资产前100人放入新数组中，相当于筛选了一遍
			book[vt[i].age]++;
		}
	}
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &num, &amin, &amax);
		vector<node> t;
		for (int j = 0; j < v.size(); j++) {
			if (v[j].age >= amin && v[j].age <= amax)
				t.push_back(v[j]);
		}
		printf("Case #%d:\n", i + 1);
		int flag = 0;
		for (int j = 0; j < num && j < t.size(); j++) {
			printf("%s %d %d\n", t[j].name, t[j].age, t[j].money);
			flag = 1;
		}
		if (flag == 0) printf("None\n");
	}
	return 0;
}
