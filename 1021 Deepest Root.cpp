# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <set>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

int n, maxheight = 0;
vector<vector<int>> v;
bool visit[10010];
set<int> s;
vector<int> temp;

void dfs(int node, int height) {
	if (height > maxheight) {  // ���߶�(���)���Ľڵ���temp
		temp.clear();
		temp.push_back(node);
		maxheight = height;
	}
	else if (height == maxheight) {
		temp.push_back(node);
	}
	visit[node] = true;  // ��4�в��ǻ�����dfs
	for (int i = 0; i < v[node].size(); i++) {
		if (visit[v[node][i]] == false) {
			dfs(v[node][i], height + 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	int a, b, cnt = 0, s1 = 0;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}  // ����Ķ�ͼ������д���������vѡ�����ö��ٿ����ٵ�д��
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			dfs(i, 1);
			if (i == 1) {  // ����ͨ����ʱ��dfs����������
				if (temp.size() != 0) s1 = temp[0];  // s1�Ǵӵ�һ��dfs���������ڵ�����ȡ��һ��������ڶ�����
				for (int j = 0; j < temp.size(); j++) {
					s.insert(temp[j]);  // һ���������ڵ��ѱ��ҳ����洢
				}
			}
			cnt++;  // cnt����ǿ��ͨ��������
		}
	}
	if (cnt >= 2) printf("Error: %d components", cnt);
	else {
		temp.clear();
		maxheight = 0;
		fill(visit, visit + 10010, false);
		dfs(s1, 1);  // �ڶ���dfs������ѡ��s1�ڵ�����������ҵ�����������нڵ�
		for (int i = 0; i < temp.size(); i++) {
			s.insert(temp[i]);  // ���뼯��s�����ϻ��Զ�ȥ�غ�����
		}
		for (auto it = s.begin(); it != s.end(); it++) {
			printf("%d\n", *it);
		}
	}
	return 0;
}