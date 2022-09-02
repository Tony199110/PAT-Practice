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
	double data;
	vector<int> child;
};
vector<node> v;
double ans = 0.0, p, r;

void dfs(int index, int depth) {
	if (v[index].child.size() == 0) {  // 叶子节点，即零售商
		ans += v[index].data * pow(1 + r, depth);
		return;
	}
	for (int i = 0; i < v[index].child.size(); i++)
		dfs(v[index].child[i], depth + 1);
}

int main() {
	int n, k, tmp;
	scanf("%d %lf %lf", &n, &p, &r);
	r = r / 100;  // 每层加价幅度
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == 0) {
			scanf("%lf", &v[i].data);
		}
		else {
			for (int j = 0; j < k; j++) {
				scanf("%d", &tmp);
				v[i].child.push_back(tmp);
			}
		}
	}  // 至此，输入完成
	dfs(0, 0);
	printf("%.1lf", ans * p);  // 最终的加价幅度 * 单价 = 最终销售额
	return 0;
}

