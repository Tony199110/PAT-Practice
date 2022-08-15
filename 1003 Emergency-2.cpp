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

int n, m, c1, c2;
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510];
const int inf = 99999999;

int main() {
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		e[a][b] = e[b][a] = c;
	}
	dis[c1] = 0;  // dis[i]表示从出发点到i节点最短路径的路径长度
	w[c1] = weight[c1];  // w[i]表示从出发点到i节点，点权之和
	num[c1] = 1;  // num[i]表示从出发点到i节点最短路径的条数
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++) {  // 这个for的目的是在每一i下，选出一个节点u，去更新与u相邻的那些邻居节点v距离起始节点的长度
			if (visit[j] == false && dis[j] < minn) {
				u = j;
				minn = dis[j];  // 找出从出发点到节点j的最短路径，记下其长度
			}
		}
		if (u == -1) break;
		visit[u] = true;  // 每轮i，只将一个节点的访问状态置为“已访问”
		for (int v = 0; v < n; v++) {
			if (visit[v] == false && e[u][v] != inf) {  // v节点未被访问过且可达
				if (dis[u] + e[u][v] < dis[v]) {  // 如果新的路径更短，则更新
					dis[v] = dis[u] + e[u][v];  // 更新最短路径长度
					num[v] = num[u];  // 更新最短路径的条数
					w[v] = w[u] + weight[v];  // 更新最短路径路过的点权之和
				}
				else if (dis[u] + e[u][v] == dis[v]) {
					num[v] = num[v] + num[u];  // 若有多条路径，增加最短路径的条数
					if (w[u] + weight[v] > w[v]) {  // 若有多条最短路径，找点权之和最大
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	}  // 至此，已经找到了从c1出发到各个节点的最短路径长度、最短路径条数、最大路过的点权之和
	printf("%d %d", num[c2], w[c2]);  // 输出需要的c2终点
	return 0;
}