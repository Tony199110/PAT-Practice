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
	int id, virtue, talent;
};
bool cmp1(struct node a, struct node b) {
	if ((a.virtue + a.talent) != (b.virtue + b.talent))
		return (a.virtue + a.talent) > (b.virtue + b.talent);
	else if (a.virtue != b.virtue)
		return a.virtue > b.virtue;
	else
		return a.id < b.id;
}

int main() {
	int n, low, high;
	scanf("%d %d %d", &n, &low, &high);
	vector<node> v[4];  // 分4类分别进行排序
	node temp;
	int total = n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &temp.id, &temp.virtue, &temp.talent);
		if (temp.virtue < low || temp.talent < low)
			total--;
		else if (temp.virtue >= high && temp.talent >= high)  // 第一类
			v[0].push_back(temp);
		else if (temp.virtue >= high && temp.talent < high)  // 第二类
			v[1].push_back(temp);
		else if (temp.virtue < high && temp.talent < high && temp.virtue >= temp.talent)  // 第三类
			v[2].push_back(temp);
		else   // 第四类
			v[3].push_back(temp);
	}
	printf("%d\n", total);
	for (int i = 0; i < 4; i++) {
		sort(v[i].begin(), v[i].end(), cmp1);
		for (int j = 0; j < v[i].size(); j++) {
			printf("%d %d %d\n", v[i][j].id, v[i][j].virtue, v[i][j].talent);
		}
	}
	return 0;
}
