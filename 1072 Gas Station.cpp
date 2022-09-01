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

const int inf = 999999999;
int n, m, k, ds, station;
int e[1020][1020], dis[1020];  // 最多1010个点
bool visit[1020];

int main() {
	fill(e[0], e[0] + 1020 * 1020, inf);
	for (int i = 0; i < 1020; i++) e[i][i] = 0;
	fill(dis, dis + 1020, inf);
	// 以上是写Dijistra必须的变量及初始化
	scanf("%d %d %d %d", &n, &m, &k, &ds);
	string s, t;
	for (int i = 0; i < k; i++) {
		int tempdis;
		cin >> s >> t >> tempdis;
		int a, b;
		if (s[0] == 'G') {
			s = s.substr(1);  // 取从第2个位置开始的子串，就是把开头的G去掉
			a = n + stoi(s);  // 加油站节点放普通节点的后面
		}
		else a = stoi(s);
		if (t[0] == 'G') {
			t = t.substr(1);
			b = n + stoi(t);
		}
		else b = stoi(t);
		e[a][b] = e[b][a] = min(tempdis, e[a][b]);  // 两个节点间可能有多条边，取最小的那条就行
	}  // 至此，输入完成
	int ansid = -1;
	double ansdis = -1, ansave = inf;
	for (int index = n + 1; index <= n + m; index++) {  // 遍历m个加油站
		double mindis = inf, ave = 0;
		fill(dis, dis + 1020, inf);
		fill(visit, visit + 1020, false);
		dis[index] = 0;
		for (int i = 1; i <= n + m; i++) {
			int u = -1, minn = inf;
			for (int j = 1; j <= n + m; j++) {
				if (visit[j] == false && dis[j] < minn) {
					u = j;
					minn = dis[j];
				}
			}
			if (u == -1) break;
			visit[u] = true;
			for (int v = 1; v <= n + m; v++) {
				if (visit[v] == false && e[u][v] != inf) {  // 可达
					if (dis[u] + e[u][v] < dis[v])  // 且更短
						dis[v] = dis[u] + e[u][v];  // 则更新
				}
			}
		}  // 至此，Dijkstra结束，算出来起始点到任意一个节点的最短距离，储存在dis数组中
		for (int i = 1; i <= n; i++) {
			if (dis[i] > ds) {
				mindis = -1;
				break;
			}
			if (dis[i] < mindis) mindis = dis[i];  // 找最小
			ave += 1.0 * dis[i];  // 求平均
		}
		if (mindis == -1) continue;  // 有超出范围的点，直接寄，下一轮
		ave /= n;
		if (mindis > ansdis) {  // 最短距离更大，那就是说更好，更新
			ansdis = mindis;
			ansid = index;
			ansave = ave;
		}
		else if (mindis == ansdis && ave < ansave) {  // 最短距离一样大，但平均距离要小，更新
			ansid = index;
			ansave = ave;
		}
	}
	if (ansid == -1) printf("No Solution");
	else printf("G%d\n%.1lf %.1lf", ansid - n, ansdis, ansave);
	return 0;
}

