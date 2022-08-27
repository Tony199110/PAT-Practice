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

int main() {
	int n, m, sum = 0;
	scanf("%d", &n);
	vector<int> dis;  // ��¼ÿ���㵽��ʼ��(1��)�ľ��룬ǰ׺��
	dis.resize(n + 2);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		sum += tmp;
		dis[i + 1] = sum;  // ��Ϊ�Ǽ�¼����һ����ľ��룬�ʹӵڶ����㿪ʼ�������±�Ϊ i + 1
	}
	scanf("%d", &m);
	int a, b, t;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a > b) swap(a, b);
		t = dis[b] - dis[a];
		printf("%d\n", min(t, sum - t));
	}
	return 0;
}
