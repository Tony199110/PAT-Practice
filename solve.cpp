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

const int maxn = 110;  // 这题最多100个节点
struct NODE {
	int weight;
	vector<int> child;
} node[maxn];

int n, m, s;
vector<int> path;
vector<vector<int>> ans;  // 存放所有路径

void dfs(int index, vector<int> path, int sum) {
	if (sum > s) return;
	if (sum == s) {
		if (node[index].child.size() != 0) return;  // 还有孩子，即未到达叶子节点
		ans.push_back(path);
		return;
	}
	for (int i = 0; i < node[index].child.size(); i++) {
		int child = node[index].child[i];  // 遍历当前节点的孩子
		path.push_back(node[child].weight);  // 加入当前节点权重
		dfs(child, path, sum + node[child].weight);  // 去下一层dfs判断是否等于目标值s
		path.pop_back();  // 若大于或等于，就会回来这一层，将刚加入的节点再去掉，说明这个节点对这条路径没用
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &node[i].weight);
	}
	int id, k, child;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			node[id].child.push_back(child);
		}
	}  // 至此完成输入
	path.push_back(node[0].weight);  // 每条路径肯定是从根节点开始的
	dfs(0, path, node[0].weight);  // 现处节点编号、已有路径、路过节点权重之和
	sort(ans.begin(), ans.end(), greater<vector<int>>());  // greater()函数，从大到小排序
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i][0]);
		for (int j = 1; j < ans[i].size(); j++) {
			printf(" %d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
