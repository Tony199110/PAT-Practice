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

const int maxn = 1010;
int n, l, k;  // 用户数 允许的最大层数 查询个数
struct node {
	int id, layer;  // 节点编号 层数
};
vector<node> adj[maxn]; // 邻接表
bool inq[maxn] = { false };

int bfs(int st, int l) {  // 起点 层数上限
	int cnt = 0;  // 转发数，即结果
	queue <node> q;  // 用队列实现，不用递归
	node start = { st, 0 };
	q.push(start);
	inq[start.id] = true;  // 标记去过的节点为true
	while (!q.empty()) {
		node topnode = q.front();
		q.pop();
		int u = topnode.id;  // 取出队首的编号
		for (int i = 0; i < adj[u].size(); i++) {  // 遍历下一层
			node next = adj[u][i];
			next.layer = topnode.layer + 1;  // 层数加一
			if (!inq[next.id] && next.layer <= l) {  // 之前未入队并且层数不大于最大层数
				q.push(next);
				inq[next.id] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n >> l;
	node user;
	for (int i = 1; i <= n; i++) {
		user.id = i;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int id;
			cin >> id;
			adj[id].push_back(user);  // 注意边的指向，id -> i
		}
	}
	cin >> k;
	int st;
	for (int i = 0; i < k; i++) {
		fill(inq, inq + maxn, false);
		cin >> st;
		int ans = bfs(st, l);
		cout << ans << endl;
	}
	return 0;
}

