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
	visit[node] = true;  // �����ʹ��Ľڵ���Ϊtrue
	for (int i = 1; i <= n; i++) {  // �������нڵ���ǿ��ͨͼ��ֻ����ô���������ǵ�
		if (visit[i] == false && v[node][i] == 1) {  // ����ǰ�ڵ㻹δ�����ʣ���i�ڵ��뵱ǰ�ڵ������ڵ�
			dfs(i);  // ˵��i�ڵ��뵱ǰ�ڵ�����ͨ�ģ����������i�ڵ�
		}
	}
}
int main() {
	int m, k, a, b;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a][b] = v[b][a] = 1;  // �ڽӾ����ͼ�����ӹ�ϵ
	}
	for (int i = 0; i < k; i++) {
		cin >> a;
		fill(visit, visit + 1001, false);  // ÿ��һ���ڵ��ǿ��ͨ��������Ҫ��������ͼΪδ����״̬
		int cnt = 0;
		visit[a] = true;  // ��ȥ���Ľڵ㣬ֻ�轫��ķ���״̬��Ϊ���ѷ��ʡ�����
		for (int j = 1; j <= n; j++) {
			if (visit[j] == false) {
				dfs(j);  // �����һ��dfs�Ϳ��Խ�һ��ǿ��ͨ����ͼ��Ϊ���ѷ��ʡ�״̬
				cnt++;  // ǿ��ͨ�����ĸ�����һ
			}
		}
		cout << cnt - 1 << endl;  // ǿ��ͨ�����ĸ��� - 1������Ҫ���ӵıߵ���������Ϊһ��ǿ��ͨ�����ʹ�����һ�Ŷ�����ͼ
	}
	return 0;
}