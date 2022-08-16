# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

const int inf = 99999999;
int cmax, n, sp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];  // 以上是写Dijkstra所需的基本变量
vector<int> pre[510], path, temppath;  // pre为邻接链表，显式地存放图的连接关系

void dfs(int v) {
	temppath.push_back(v);
	if (v == 0) {  // 从终点一直搜索到起点，到起点后才进入这个if
		int need = 0, back = 0;
		for (int i = temppath.size() - 1; i >= 0; i--) {  // 从起始点遍历到终点，去的路上就要使所有车站满足完美状态
			int id = temppath[i];
			if (weight[id] > 0) {  // 如果比完美状态大，就需要把多余的自行车带走
				back += weight[id];
			}
			else {
				if (back > (0 - weight[id])) {  // 如果有车站少自行车，且带回来的back能够满足
					back += weight[id];  // 则back吐出0 - weight[id]辆车，即back减小
				}
				else {  // 如果有车站少自行车，但带回来的back满足不了，
					need += ((0 - weight[id]) - back);  // back吐出来后还有的缺口只能由调度中心增加带出来的车辆，即need增加
					back = 0;  // 让back全吐出来，即置0
				}
			}
		}
		if (need < minNeed) {  // 先need最小
			minNeed = need;
			minBack = back;
			path = temppath;
		}
		else if (need == minNeed && back < minBack) {  // 若need已经最小，则再取back最小
			minBack = back;
			path = temppath;
		}
		temppath.pop_back();  // 这条路径完成，pop掉尾巴的一个元素，去找第二条路径
		return;
	}
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);  // 从后往前深度搜索，只要节点之间先连接，就去搜索
	}
	temppath.pop_back();  // 搜索进去可能扑了个空，那就需要将刚进入函数的push_back给pop掉
	return;
}

int main() {
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	scanf("%d %d %d %d", &cmax, &n, &sp, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &weight[i]);
		weight[i] = weight[i] - cmax / 2;  // 现在0是完美状态
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[a][b] = e[b][a] = c;
	}  // 输入完成
	// 开始写Dijkstra算法
	dis[0] = 0;  // 这题节点0为起始点
	for (int i = 0; i <= n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j <= n; j++) {  // 每次取出未访问节点中距离最小的，记为u
			if (visit[j] == false && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1) break;
		visit[u] = true;
		for (int v = 0; v <= n; v++) {
			if (visit[v] == false && e[u][v] != inf) {
				if (dis[u] + e[u][v] < dis[v]) {
					dis[v] = dis[u] + e[u][v];  // 每次都有的最基本的更新
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[u] + e[u][v] == dis[v]) {
					pre[v].push_back(u);  // 记下u到v的最短的所有路径
				}
			}
		}
	}
	dfs(sp);
	printf("%d 0", minNeed);
	for (int i = path.size() - 2; i >= 0; i--) {
		printf("->%d", path[i]);
	}
	printf(" %d", minBack);
	return 0;
}