# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

const int maxn = 10005;
struct node {
	int come, time;  // come是到银行的时间，time是所需的服务时间
} p[maxn];
int cmp(node n1, node n2) {
	return n1.come < n2.come;  // 先来的先服务
}
int n, k, cnt = 0, total = 0;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int hh, mm, ss, tt;
		scanf("%02d:%02d:%02d %d", &hh, &mm, &ss, &tt);
		int sum = hh * 3600 + mm * 60 + ss;  // 将hh:mm:ss格式的时间转换为以当天0点为基准的秒数
		if (sum > 17 * 3600) continue;  // 晚于17:00来的人直接忽视
		p[++cnt].time = tt * 60;
		p[cnt].come = sum;
	}
	sort(p + 1, p + 1 + cnt, cmp);  // 按照到达的先后顺序排序
	priority_queue<int, vector<int>, greater<int>> q;  // 优先队列，升序
	for (int i = 1; i <= k; i++) q.push(8 * 3600);  // 初始化这个长度为窗口数量k的优先队列
	for (int i = 1; i <= cnt; i++) {
		if (q.top() <= p[i].come) {  // 不需要等
			q.push(p[i].come + p[i].time);
			q.pop();
		}
		else {  // 等待一段时间
			total += q.top() - p[i].come;
			q.push(q.top() + p[i].time);
			q.pop();
		}
	}
	(!cnt) ? printf("0.0\n") : printf("%.1lf", (total / 60.0) / cnt);
	return 0;
}