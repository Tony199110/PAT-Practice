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

int n, k, group, lastnum, maxn = -1, maxid, temp;

int main() {
	scanf("%d %d", &n, &k);  // һ��n���ˣ�һ��k����
	vector<int> weight(n), rank(n);
	queue<int> mice;
	for (int i = 0; i < n; i++)
		scanf("%d", &weight[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		mice.push(temp);
	}
	lastnum = n;
	while (lastnum > 1) {
		group = lastnum / k + (lastnum % k == 0 ? 0 : 1);  // �ֳܷɵ�����
		for (int i = 1; i <= lastnum; i++) {
			temp = mice.front();
			if (maxn < weight[temp]) {
				maxn = weight[temp];
				maxid = temp;
			}
			rank[temp] = group + 1;   // ��������Ϊ��һ�������˵����ζ���δ���������Σ���һ�ֻ������Щ�������˵�����
			mice.pop();  // ���ϵ����Ѿ�����ʤ������
			if (i % k == 0 || i == lastnum) {
				mice.push(maxid);  // ����ʤ���˼���ѹ�����
				maxn = -1;  // ÿһ���ҳ�һ�����ֵ��Ȼ���������ֵΪ-1����������һ��
			}
		}
		lastnum = mice.size();
	}
	rank[mice.front()] = 1;  // ���ʣ�µ��Ǹ����ǵ�һ��
	printf("%d", rank[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", rank[i]);
	return 0;
}
