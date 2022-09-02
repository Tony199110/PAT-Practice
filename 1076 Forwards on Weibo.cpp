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

const int maxn = 1010;
int n, l, k;  // �û��� ����������� ��ѯ����
struct node {
	int id, layer;  // �ڵ��� ����
};
vector<node> adj[maxn]; // �ڽӱ�
bool inq[maxn] = { false };

int bfs(int st, int l) {  // ��� ��������
	int cnt = 0;  // ת�����������
	queue <node> q;  // �ö���ʵ�֣����õݹ�
	node start = { st, 0 };
	q.push(start);
	inq[start.id] = true;  // ���ȥ���Ľڵ�Ϊtrue
	while (!q.empty()) {
		node topnode = q.front();
		q.pop();
		int u = topnode.id;  // ȡ�����׵ı��
		for (int i = 0; i < adj[u].size(); i++) {  // ������һ��
			node next = adj[u][i];
			next.layer = topnode.layer + 1;  // ������һ
			if (!inq[next.id] && next.layer <= l) {  // ֮ǰδ��Ӳ��Ҳ���������������
				q.push(next);
				inq[next.id] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n >> l;
	node user;
	for (int i = 1; i <= n; i++) {
		user.id = i;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int id;
			cin >> id;
			adj[id].push_back(user);  // ע��ߵ�ָ��id -> i
		}
	}
	cin >> k;
	int st;
	for (int i = 0; i < k; i++) {
		fill(inq, inq + maxn, false);
		cin >> st;
		int ans = bfs(st, l);
		cout << ans << endl;
	}
	return 0;
}

