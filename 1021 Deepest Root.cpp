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
	if (height > maxheight) {  // 将高度(深度)最大的节点存进temp
		temp.clear();
		temp.push_back(node);
		maxheight = height;
	}
	else if (height == maxheight) {
		temp.push_back(node);
	}
	visit[node] = true;  // 这4行才是基础的dfs
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
	}  // 经典的对图的输入写法，这里的v选择了用多少开多少的写法
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			dfs(i, 1);
			if (i == 1) {  // 找连通分量时的dfs被二次利用
				if (temp.size() != 0) s1 = temp[0];  // s1是从第一遍dfs后的最大距离节点中任取的一个，后面第二遍用
				for (int j = 0; j < temp.size(); j++) {
					s.insert(temp[j]);  // 一侧的最大距离节点已被找出，存储
				}
			}
			cnt++;  // cnt代表强连通分量个数
		}
	}
	if (cnt >= 2) printf("Error: %d components", cnt);
	else {
		temp.clear();
		maxheight = 0;
		fill(visit, visit + 10010, false);
		dfs(s1, 1);  // 第二次dfs，从任选的s1节点出发，即可找到距离最长的所有节点
		for (int i = 0; i < temp.size(); i++) {
			s.insert(temp[i]);  // 存入集合s，集合会自动去重和排序
		}
		for (auto it = s.begin(); it != s.end(); it++) {
			printf("%d\n", *it);
		}
	}
	return 0;
}