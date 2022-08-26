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
/*  // �������map<string, set<int>>���Թ����������ݺ�ʱ369ms���ڴ�45MB
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

// ������ӳ��Ϊ��ţ����������±ꣻ�������ݺ�ʱ71ms���ڴ�10MB
int getid(char* name) {  // ���̶���ʽΪ3����д��ĸ+1�����ֵ�����ת����1���������������Ϊ������id
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = 26 * id + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];  // ��������±�������ÿ��ѧ��������id
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