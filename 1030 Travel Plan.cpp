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
int e[510][510], dis[510], cost[510][510];  // �ֱ��ߵĳ���(��һ��Ȩ)����ĳ��ľ��롢�ڶ���Ȩ
bool visit[510];
vector<int> pre[510];  // pre�Ǽ�¼���·�����ڽ�����������дDijistra����Ļ�������
vector<int> path, temppath;  // дdfs�õ�
int mincost = inf;  // ������ɵڶ���Ȩ����������Ŀ�꺯��
void dfs(int v) {
	temppath.push_back(v);
	if (v == s) {  // ��ʱ��һ�����·���ѱ���������ˣ�ȥ��Ŀ�꺯��
		int tempcost = 0;  // ��ͬ�������·����ǰ���£�tempcost��Ŀ�꺯��������С
		for (int i = temppath.size() - 1; i > 0; i--) {  // ����ʼ��������յ�
			int id = temppath[i], nextid = temppath[i - 1];
			tempcost += cost[id][nextid];  // ����ÿ���ߵĵڶ���Ȩ�������Ǽ۸�
		}  // ���ˣ������һ�����·����Ŀ�꺯��
		if (tempcost < mincost) {  // ȡ��С��Ŀ�꺯��
			mincost = tempcost;  // ������Сֵ
			path = temppath;  // �������Ҫ�����·��
		}
		temppath.pop_back();  // �����������·��������ȥ
		return;
	}
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	temppath.pop_back();
}

int main() {
	fill(e[0], e[0] + 510 * 510, inf);  // ��ʼ�����е�֮������ɴ����������Զ
	fill(dis, dis + 510, inf);  // 
	scanf("%d %d %d %d", &n, &m, &s, &d);  // ��ʼ����
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		scanf("%d", &e[a][b]);
		e[b][a] = e[a][b];
		scanf("%d", &cost[a][b]);
		cost[b][a] = cost[a][b];
	}  // ������ɡ����濪ʼдDijistra
	dis[s] = 0;  // ��sΪ��ʼ��
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j <= n; j++) {  // ÿ��ȡ��δ���ʽڵ��о�����С�ģ���Ϊu
			if (visit[j] == false && dis[j] < minn) {
				minn = dis[j];
				u = j;
			}
		}
		if (u == -1) break;
		visit[u] = true;  // �ߵ�u�ڵ㣬��Ϊ������һ���ڵ����
		for (int v = 0; v < n; v++) {  // ȥ����u�������һ���ڵ�
			if (visit[v] == false && e[u][v] != inf) {
				if (dis[u] + e[u][v] < dis[v]) {
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);  // u���ǵ�v�����
				}
				else if (dis[u] + e[u][v] == dis[v]) {
					pre[v].push_back(u);  // ��ֹһ��u��v���
				}
			}
		}
	}
	dfs(d);  // ���յ㿪ʼ���أ���pre�ڽ������С���ȡ�������·����������ÿ�����·���Ļ���
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("%d %d", dis[d], mincost);
	return 0;
}