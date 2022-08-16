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
bool visit[510];  // ������дDijkstra����Ļ�������
vector<int> pre[510], path, temppath;  // preΪ�ڽ�������ʽ�ش��ͼ�����ӹ�ϵ

void dfs(int v) {
	temppath.push_back(v);
	if (v == 0) {  // ���յ�һֱ��������㣬������Ž������if
		int need = 0, back = 0;
		for (int i = temppath.size() - 1; i >= 0; i--) {  // ����ʼ��������յ㣬ȥ��·�Ͼ�Ҫʹ���г�վ��������״̬
			int id = temppath[i];
			if (weight[id] > 0) {  // ���������״̬�󣬾���Ҫ�Ѷ�������г�����
				back += weight[id];
			}
			else {
				if (back > (0 - weight[id])) {  // ����г�վ�����г����Ҵ�������back�ܹ�����
					back += weight[id];  // ��back�³�0 - weight[id]��������back��С
				}
				else {  // ����г�վ�����г�������������back���㲻�ˣ�
					need += ((0 - weight[id]) - back);  // back�³������е�ȱ��ֻ���ɵ����������Ӵ������ĳ�������need����
					back = 0;  // ��backȫ�³���������0
				}
			}
		}
		if (need < minNeed) {  // ��need��С
			minNeed = need;
			minBack = back;
			path = temppath;
		}
		else if (need == minNeed && back < minBack) {  // ��need�Ѿ���С������ȡback��С
			minBack = back;
			path = temppath;
		}
		temppath.pop_back();  // ����·����ɣ�pop��β�͵�һ��Ԫ�أ�ȥ�ҵڶ���·��
		return;
	}
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);  // �Ӻ���ǰ���������ֻҪ�ڵ�֮�������ӣ���ȥ����
	}
	temppath.pop_back();  // ������ȥ�������˸��գ��Ǿ���Ҫ���ս��뺯����push_back��pop��
	return;
}

int main() {
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	scanf("%d %d %d %d", &cmax, &n, &sp, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &weight[i]);
		weight[i] = weight[i] - cmax / 2;  // ����0������״̬
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[a][b] = e[b][a] = c;
	}  // �������
	// ��ʼдDijkstra�㷨
	dis[0] = 0;  // ����ڵ�0Ϊ��ʼ��
	for (int i = 0; i <= n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j <= n; j++) {  // ÿ��ȡ��δ���ʽڵ��о�����С�ģ���Ϊu
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
					dis[v] = dis[u] + e[u][v];  // ÿ�ζ��е�������ĸ���
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[u] + e[u][v] == dis[v]) {
					pre[v].push_back(u);  // ����u��v����̵�����·��
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