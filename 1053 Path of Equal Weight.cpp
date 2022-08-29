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

const int maxn = 110;  // �������100���ڵ�
struct NODE {
	int weight;
	vector<int> child;
} node[maxn];

int n, m, s;
vector<int> path;
vector<vector<int>> ans;  // �������·��

void dfs(int index, vector<int> path, int sum) {
	if (sum > s) return;
	if (sum == s) {
		if (node[index].child.size() != 0) return;  // ���к��ӣ���δ����Ҷ�ӽڵ�
		ans.push_back(path);
		return;
	}
	for (int i = 0; i < node[index].child.size(); i++) {
		int child = node[index].child[i];  // ������ǰ�ڵ�ĺ���
		path.push_back(node[child].weight);  // ���뵱ǰ�ڵ�Ȩ��
		dfs(child, path, sum + node[child].weight);  // ȥ��һ��dfs�ж��Ƿ����Ŀ��ֵs
		path.pop_back();  // �����ڻ���ڣ��ͻ������һ�㣬���ռ���Ľڵ���ȥ����˵������ڵ������·��û��
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &node[i].weight);
	}
	int id, k, child;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			node[id].child.push_back(child);
		}
	}  // �����������
	path.push_back(node[0].weight);  // ÿ��·���϶��ǴӸ��ڵ㿪ʼ��
	dfs(0, path, node[0].weight);  // �ִ��ڵ��š�����·����·���ڵ�Ȩ��֮��
	sort(ans.begin(), ans.end(), greater<vector<int>>());  // greater()�������Ӵ�С����
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i][0]);
		for (int j = 1; j < ans[i].size(); j++) {
			printf(" %d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
