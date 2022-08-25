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

int stoifunc(string s) {  // ���ַ���(����һ���)ת���ɴ�1��ʼ���ֱ��
	if (stringToInt[s] == 0) {
		stringToInt[s] = idNumber;
		intToString[idNumber] = s;  // ��Ӧ��ϵ��Ҫ2��map�����
		return idNumber++;
	}
	else {
		return stringToInt[s];
	}
}
int weight[2010], G[2010][2010];  // weight���Ȩ��G���Ȩ
bool visit[2010];  // dfs����ͨ��������ʱҪ��
void dfs(int u, int &head, int &numMember, int &totalweight) {
	numMember++;  // �ڵ�����һ
	if (weight[u] > weight[head]) {
		head = u;
	}
	
	visit[u] = true;
	for (int v = 1; v < idNumber; v++) {
		if (G[u][v] > 0) {  // ���ﲻ�Ǵ�ͳ�ġ�δ���������ڡ���������Ϊ������Ҫȥ�������бߣ����Ǳ����ڵ�
			totalweight += G[u][v];  // ����Ŀ��֮һ���������нڵ�ĵ�Ȩ֮�ͣ�����ڵ��Ȩ��Դ����֮���ڵı�
			G[u][v] = G[v][u] = 0;  // ��ֹ�ظ�����ͬһ����
			if (visit[v] == false) {
				dfs(v, head, numMember, totalweight);  // ����ÿ��ȥһ�Σ��ܽ�һ���ڵ�v��������Ϣ�����
			}
		}
	}
}

void dfsTrave() {  // ��dfs�������䣬��һ��ͼ����ͨ����������ͼ
	for (int i = 1; i < idNumber; i++) {  // ����ͨ����
		if (visit[i] == false) {
			int head = i, numMember = 0, totalweight = 0;
			dfs(i, head, numMember, totalweight);  // ������ÿ��ȥһ�Σ�һ�����ҵ�һ����ͼ
			if (numMember > 2 && totalweight > k) {  // �����������˶���2���ܱ�Ȩ������ֵk
				ans[intToString[head]] = numMember;  // ���ϴ�����Ż����������ǽ�ÿ����ͼ����������Ӧ����
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