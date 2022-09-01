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
int e[1020][1020], dis[1020];  // ���1010����
bool visit[1020];

int main() {
	fill(e[0], e[0] + 1020 * 1020, inf);
	for (int i = 0; i < 1020; i++) e[i][i] = 0;
	fill(dis, dis + 1020, inf);
	// ������дDijistra����ı�������ʼ��
	scanf("%d %d %d %d", &n, &m, &k, &ds);
	string s, t;
	for (int i = 0; i < k; i++) {
		int tempdis;
		cin >> s >> t >> tempdis;
		int a, b;
		if (s[0] == 'G') {
			s = s.substr(1);  // ȡ�ӵ�2��λ�ÿ�ʼ���Ӵ������ǰѿ�ͷ��Gȥ��
			a = n + stoi(s);  // ����վ�ڵ����ͨ�ڵ�ĺ���
		}
		else a = stoi(s);
		if (t[0] == 'G') {
			t = t.substr(1);
			b = n + stoi(t);
		}
		else b = stoi(t);
		e[a][b] = e[b][a] = min(tempdis, e[a][b]);  // �����ڵ������ж����ߣ�ȡ��С����������
	}  // ���ˣ��������
	int ansid = -1;
	double ansdis = -1, ansave = inf;
	for (int index = n + 1; index <= n + m; index++) {  // ����m������վ
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
				if (visit[v] == false && e[u][v] != inf) {  // �ɴ�
					if (dis[u] + e[u][v] < dis[v])  // �Ҹ���
						dis[v] = dis[u] + e[u][v];  // �����
				}
			}
		}  // ���ˣ�Dijkstra�������������ʼ�㵽����һ���ڵ����̾��룬������dis������
		for (int i = 1; i <= n; i++) {
			if (dis[i] > ds) {
				mindis = -1;
				break;
			}
			if (dis[i] < mindis) mindis = dis[i];  // ����С
			ave += 1.0 * dis[i];  // ��ƽ��
		}
		if (mindis == -1) continue;  // �г�����Χ�ĵ㣬ֱ�Ӽģ���һ��
		ave /= n;
		if (mindis > ansdis) {  // ��̾�������Ǿ���˵���ã�����
			ansdis = mindis;
			ansid = index;
			ansave = ave;
		}
		else if (mindis == ansdis && ave < ansave) {  // ��̾���һ���󣬵�ƽ������ҪС������
			ansid = index;
			ansave = ave;
		}
	}
	if (ansid == -1) printf("No Solution");
	else printf("G%d\n%.1lf %.1lf", ansid - n, ansdis, ansave);
	return 0;
}

