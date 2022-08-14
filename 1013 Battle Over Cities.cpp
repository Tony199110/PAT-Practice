# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

int v[1001][1001];
bool visit[1001];
int n;
void dfs(int node) {
	visit[node] = true;  // 将访问过的节点置为true
	for (int i = 1; i <= n; i++) {  // 遍历所有节点找强连通图，只能这么做？恐怕是的
		if (visit[i] == false && v[node][i] == 1) {  // 若当前节点还未被访问，且i节点与当前节点是相邻的
			dfs(i);  // 说明i节点与当前节点是连通的，则深度搜索i节点
		}
	}
}
int main() {
	int m, k, a, b;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a][b] = v[b][a] = 1;  // 邻接矩阵存图的连接关系
	}
	for (int i = 0; i < k; i++) {
		cin >> a;
		fill(visit, visit + 1001, false);  // 每做一个节点的强连通分量，需要重置整张图为未访问状态
		int cnt = 0;
		visit[a] = true;  // 被去掉的节点，只需将其的访问状态置为“已访问”即可
		for (int j = 1; j <= n; j++) {
			if (visit[j] == false) {
				dfs(j);  // 这里的一个dfs就可以将一张强连通分量图置为“已访问”状态
				cnt++;  // 强连通分量的个数加一
			}
		}
		cout << cnt - 1 << endl;  // 强连通分量的个数 - 1就是需要增加的边的条数，因为一个强连通分量就代表着一张独立的图
	}
	return 0;
}