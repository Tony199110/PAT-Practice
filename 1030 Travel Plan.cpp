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

const int inf = 9999999;
int n, m, s, d;
int e[510][510], dis[510], cost[510][510];  // 分别存边的长度(第一边权)、到某点的距离、第二边权
bool visit[510];
vector<int> pre[510];  // pre是记录最短路径的邻接链表。以上是写Dijistra所需的基本变量
vector<int> path, temppath;  // 写dfs用的
int mincost = inf;  // 此题的由第二边权衍生出来的目标函数
void dfs(int v) {
	temppath.push_back(v);
	if (v == s) {  // 此时，一条最短路径已被构造出来了，去算目标函数
		int tempcost = 0;  // 在同样是最短路径的前提下，tempcost是目标函数，求最小
		for (int i = temppath.size() - 1; i > 0; i--) {  // 从起始点遍历到终点
			int id = temppath[i], nextid = temppath[i - 1];
			tempcost += cost[id][nextid];  // 遍历每条边的第二边权，这题是价格
		}  // 至此，算出了一条最短路径的目标函数
		if (tempcost < mincost) {  // 取最小的目标函数
			mincost = tempcost;  // 更新最小值
			path = temppath;  // 更新最后要输出的路径
		}
		temppath.pop_back();  // 把这条算完的路径给弹出去
		return;
	}
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	temppath.pop_back();
}

int main() {
	fill(e[0], e[0] + 510 * 510, inf);  // 初始化所有点之间均不可达，即距离无限远
	fill(dis, dis + 510, inf);  // 
	scanf("%d %d %d %d", &n, &m, &s, &d);  // 开始输入
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		scanf("%d", &e[a][b]);
		e[b][a] = e[a][b];
		scanf("%d", &cost[a][b]);
		cost[b][a] = cost[a][b];
	}  // 输入完成。下面开始写Dijistra
	dis[s] = 0;  // 以s为起始点
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j <= n; j++) {  // 每次取出未访问节点中距离最小的，记为u
			if (visit[j] == false && dis[j] < minn) {
				minn = dis[j];
				u = j;
			}
		}
		if (u == -1) break;
		visit[u] = true;  // 走到u节点，因为距离上一个节点最短
		for (int v = 0; v < n; v++) {  // 去找离u最近的下一个节点
			if (visit[v] == false && e[u][v] != inf) {
				if (dis[u] + e[u][v] < dis[v]) {
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);  // u才是到v最近的
				}
				else if (dis[u] + e[u][v] == dis[v]) {
					pre[v].push_back(u);  // 不止一个u到v最近
				}
			}
		}
	}
	dfs(d);  // 从终点开始往回，从pre邻接链表中“提取”出最短路径，并计算每条最短路径的花费
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("%d %d", dis[d], mincost);
	return 0;
}