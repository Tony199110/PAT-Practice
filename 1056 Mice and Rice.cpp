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
	scanf("%d %d", &n, &k);  // 一共n个人，一组k个人
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
		group = lastnum / k + (lastnum % k == 0 ? 0 : 1);  // 能分成的组数
		for (int i = 1; i <= lastnum; i++) {
			temp = mice.front();
			if (maxn < weight[temp]) {
				maxn = weight[temp];
				maxid = temp;
			}
			rank[temp] = group + 1;   // 可以先认为这一次所有人的名次都是未晋级的名次，下一轮会更新那些晋级的人的名次
			mice.pop();  // 不断弹出已经决出胜负的人
			if (i % k == 0 || i == lastnum) {
				mice.push(maxid);  // 将获胜的人继续压入队列
				maxn = -1;  // 每一组找出一个最大值，然后重置最大值为-1，继续找下一组
			}
		}
		lastnum = mice.size();
	}
	rank[mice.front()] = 1;  // 最后剩下的那个就是第一名
	printf("%d", rank[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", rank[i]);
	return 0;
}
