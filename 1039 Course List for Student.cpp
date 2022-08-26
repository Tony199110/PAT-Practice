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
/*  // 这道题用map<string, set<int>>可以过，最大的数据耗时369ms，内存45MB
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int cosid, num;
	string name;
	map<string, set<int>> query;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &cosid, &num);
		for (int j = 0; j < num; j++) {
			cin >> name;
			query[name].insert(cosid);
		}
	}
	string qname;
	for (int i = 0; i < n; i++) {
		cin >> qname;
		int len = query[qname].size();
		cout << qname << " " << len;
		for (auto it = query[qname].begin(); it != query[qname].end(); it++) {
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
} */

// 将姓名映射为编号，当做数组下标；最大的数据耗时71ms，内存10MB
int getid(char* name) {  // 将固定格式为3个大写字母+1个数字的名字转换成1个整型数，可理解为姓名的id
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = 26 * id + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];  // 用数组的下标来索引每个学生姓名的id
int main() {
	int n, k, cosid, num, id = 0;
	char name[5];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &cosid, &num);
		for (int j = 0; j < num; j++) {
			scanf("%s", name);
			id = getid(name);
			v[id].push_back(cosid);
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", name);
		id = getid(name);
		sort(v[id].begin(), v[id].end());
		printf("%s %lu", name, v[id].size());
		for (int j = 0; j < v[id].size(); j++)
			printf(" %d", v[id][j]);
		printf("\n");
	}
	return 0;
}