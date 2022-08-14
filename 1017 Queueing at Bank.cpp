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
	int come, time;  // come�ǵ����е�ʱ�䣬time������ķ���ʱ��
} p[maxn];
int cmp(node n1, node n2) {
	return n1.come < n2.come;  // �������ȷ���
}
int n, k, cnt = 0, total = 0;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int hh, mm, ss, tt;
		scanf("%02d:%02d:%02d %d", &hh, &mm, &ss, &tt);
		int sum = hh * 3600 + mm * 60 + ss;  // ��hh:mm:ss��ʽ��ʱ��ת��Ϊ�Ե���0��Ϊ��׼������
		if (sum > 17 * 3600) continue;  // ����17:00������ֱ�Ӻ���
		p[++cnt].time = tt * 60;
		p[cnt].come = sum;
	}
	sort(p + 1, p + 1 + cnt, cmp);  // ���յ�����Ⱥ�˳������
	priority_queue<int, vector<int>, greater<int>> q;  // ���ȶ��У�����
	for (int i = 1; i <= k; i++) q.push(8 * 3600);  // ��ʼ���������Ϊ��������k�����ȶ���
	for (int i = 1; i <= cnt; i++) {
		if (q.top() <= p[i].come) {  // ����Ҫ��
			q.push(p[i].come + p[i].time);
			q.pop();
		}
		else {  // �ȴ�һ��ʱ��
			total += q.top() - p[i].come;
			q.push(q.top() + p[i].time);
			q.pop();
		}
	}
	(!cnt) ? printf("0.0\n") : printf("%.1lf", (total / 60.0) / cnt);
	return 0;
}