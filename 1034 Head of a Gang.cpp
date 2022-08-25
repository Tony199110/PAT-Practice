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

map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> ans;
int idNumber = 1, k;

int stoifunc(string s) {  // 将字符串(名字一类的)转换成从1开始数字编号
	if (stringToInt[s] == 0) {
		stringToInt[s] = idNumber;
		intToString[idNumber] = s;  // 对应关系需要2个map来完成
		return idNumber++;
	}
	else {
		return stringToInt[s];
	}
}
int weight[2010], G[2010][2010];  // weight存点权，G存边权
bool visit[2010];  // dfs求连通分量个数时要用
void dfs(int u, int &head, int &numMember, int &totalweight) {
	numMember++;  // 节点数加一
	if (weight[u] > weight[head]) {
		head = u;
	}
	
	visit[u] = true;
	for (int v = 1; v < idNumber; v++) {
		if (G[u][v] > 0) {  // 这里不是传统的“未访问且相邻”条件，因为这里是要去遍历所有边，而非遍历节点
			totalweight += G[u][v];  // 此行目的之一：计算所有节点的点权之和，这里节点点权来源于与之相邻的边
			G[u][v] = G[v][u] = 0;  // 防止重复遍历同一条边
			if (visit[v] == false) {
				dfs(v, head, numMember, totalweight);  // 这里每进去一次，能将一个节点v的所有信息算出来
			}
		}
	}
}

void dfsTrave() {  // 与dfs函数搭配，找一张图的连通分量，即子图
	for (int i = 1; i < idNumber; i++) {  // 找连通分量
		if (visit[i] == false) {
			int head = i, numMember = 0, totalweight = 0;
			dfs(i, head, numMember, totalweight);  // 从这里每进去一次，一定能找到一个子图
			if (numMember > 2 && totalweight > k) {  // 满足条件，人多于2、总边权大于阈值k
				ans[intToString[head]] = numMember;  // 给老大记上团伙人数，就是将每个子图与其人数对应起来
			}
			cout << numMember << " " << totalweight << endl;
		}
	}
}

int main() {
	int n, w;
	scanf("%d %d", &n, &k);
	string s1, s2;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2 >> w;
		int id1 = stoifunc(s1);
		int id2 = stoifunc(s2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	dfsTrave();
	printf("%d\n", ans.size());
	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}