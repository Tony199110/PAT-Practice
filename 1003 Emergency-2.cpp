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
	dis[c1] = 0;  // dis[i]��ʾ�ӳ����㵽i�ڵ����·����·������
	w[c1] = weight[c1];  // w[i]��ʾ�ӳ����㵽i�ڵ㣬��Ȩ֮��
	num[c1] = 1;  // num[i]��ʾ�ӳ����㵽i�ڵ����·��������
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++) {  // ���for��Ŀ������ÿһi�£�ѡ��һ���ڵ�u��ȥ������u���ڵ���Щ�ھӽڵ�v������ʼ�ڵ�ĳ���
			if (visit[j] == false && dis[j] < minn) {
				u = j;
				minn = dis[j];  // �ҳ��ӳ����㵽�ڵ�j�����·���������䳤��
			}
		}
		if (u == -1) break;
		visit[u] = true;  // ÿ��i��ֻ��һ���ڵ�ķ���״̬��Ϊ���ѷ��ʡ�
		for (int v = 0; v < n; v++) {
			if (visit[v] == false && e[u][v] != inf) {  // v�ڵ�δ�����ʹ��ҿɴ�
				if (dis[u] + e[u][v] < dis[v]) {  // ����µ�·�����̣������
					dis[v] = dis[u] + e[u][v];  // �������·������
					num[v] = num[u];  // �������·��������
					w[v] = w[u] + weight[v];  // �������·��·���ĵ�Ȩ֮��
				}
				else if (dis[u] + e[u][v] == dis[v]) {
					num[v] = num[v] + num[u];  // ���ж���·�����������·��������
					if (w[u] + weight[v] > w[v]) {  // ���ж������·�����ҵ�Ȩ֮�����
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	}  // ���ˣ��Ѿ��ҵ��˴�c1�����������ڵ�����·�����ȡ����·�����������·���ĵ�Ȩ֮��
	printf("%d %d", num[c2], w[c2]);  // �����Ҫ��c2�յ�
	return 0;
}