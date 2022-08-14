# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

struct node {
	int poptime, endtime;  // poptime代表队首的人出队的时间，endtime代表队尾的人出队的时间
	queue<int> q;  // 表示当前窗口的排队队列
};

int main() {
	int n, m, k, q, index = 1;  // index是遍历k个客户服务时间用的，贯穿全文
	scanf("%d %d %d %d", &n, &m, &k, &q);
	vector<int> time(k + 1), result(k + 1);  // 数组不能用变量k声明，而vector可以
	for (int i = 1; i <= k; i++) {
		scanf("%d", &time[i]);
	}
	vector<node> window(n + 1); // 为每个窗口都维持一个队列
	vector<bool> sorry(k + 1, false);  // 
	for (int i = 1; i <= m; i++) {  // 遍历窗口队列容量，即再装第二排，
		for (int j = 1; j <= n; j++) {  // 遍历窗口，即先装第一排，
			if (index <= k) {  // 用于截断k<n*m的情况，k>n*m时，这个if会一直成立
				window[j].q.push(time[index]);  // 初始化，将客户一个个装进队列里
				if (window[j].endtime >= (17 - 8) * 60) {
					sorry[index] = true;  // 若当前该队列队尾出队的时刻超过了17点，则新入队的人只能sorry
				}
				window[j].endtime += time[index];  // 每入队一个人就要更新当前队列的endtime
				if (i == 1) {
					window[j].poptime = window[j].endtime;
				}
				result[index] = window[j].endtime;
				index++;
			}
		}
	}  // 至此，初始化完成，即将黄线内的人塞满了
	while (index <= k) {  // 若黄线外没人，则这个while就不用进去
		int tempmin = window[1].poptime, tempwindow = 1;
		for (int i = 2; i <= n; i++) {
			if (window[i].poptime < tempmin) {  // 找队首最快结束服务的各窗口
				tempmin = window[i].poptime;
				tempwindow = i;
			}
		}
		window[tempwindow].q.pop();  // 找到最快结束服务的客户后，让他出队
		window[tempwindow].q.push(time[index]);  // 出队后，让黄线外的下一个客户进入这个队列
		window[tempwindow].poptime += window[tempwindow].q.front();
		if (window[tempwindow].endtime >= (17 - 8) * 60) {
			sorry[index] = true;
		}
		window[tempwindow].endtime += time[index];
		result[index] = window[tempwindow].endtime;
		index++;
	}  // 至此，完成k个客户的服务
	for (int i = 1; i <= q; i++) {
		int query, minute;
		scanf("%d", &query);
		minute = result[query];
		if (sorry[query] == true) {
			printf("Sorry\n");
		}
		else {
			printf("%02d:%02d\n", minute / 60 + 8, minute % 60);
		}
	}
	return 0;
}