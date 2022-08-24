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

const int inf = 99999999;
struct station {
	double price, dis;  // 每个加油站的油价和距起始点距离
};
bool cmp1(station a, station b) {
	return a.dis < b.dis;
}

int main() {
	double cmax, d, davg;
	int n;
	scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
	vector<station> sta(n + 1);
	sta[0] = { 0.0, d };
	for (int i = 1; i <= n; i++) {
		scanf("%lf %lf", &sta[i].price, &sta[i].dis);
	}  // 输入完成
	sort(sta.begin(), sta.end(), cmp1);
	double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;
	if (sta[0].dis != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;  // 很特殊的情况，第一站不在起始点处，那没有油就开不起来
	}
	else {
		nowprice = sta[0].price;  // 初始化当前油价为起始点油价
	}
	while (nowdis < d) {  // 没走到终点就继续
		maxdis = nowdis + cmax * davg;  // 加满油能跑的最大距离
		double minPriceDis = 0.0, minPrice = inf;
		int flag = 0;
		for (int i = 1; i <= n && sta[i].dis <= maxdis; i++) {  // 去遍历能到达的加油站
			if (sta[i].dis <= nowdis) continue;  // 跳过已经走过的加油站
			// 情况一
			if (sta[i].price < nowprice) {  // 如果后面有加油站的油价比当前的便宜，就去最近的那个，大赚
				totalPrice += nowprice * (sta[i].dis - nowdis - leftdis) / davg;  // 油价 * 所需油数量
				leftdis = 0.0;
				nowprice = sta[i].price;
				nowdis = sta[i].dis;
				flag = 1;
				break;
			}
			if (sta[i].price < minPrice) {  // 如果没有大赚的情况，就去找尽可能低的油价
				minPrice = sta[i].price;
				minPriceDis = sta[i].dis;
			}
		}
		// 情况二
		if (flag == 0 && minPrice != inf) {  // 没有比当前加油站更低的油价，只能去其中最低的那个加油站，当场加满，少亏一点
			totalPrice += nowprice * (cmax - leftdis / davg);  // 油价 * (加满所需油数量 = 油箱容量 - 上次剩下的油)
			leftdis = cmax * davg - (minPriceDis - nowdis);  // 
			nowprice = minPrice;
			nowdis = minPriceDis;
		}
		// 情况三
		if (flag == 0 && minPrice == inf) {  // 最大距离无法抵达不了下一个车站，为不可达的情况
			nowdis += cmax * davg;  // 索性加满，能开多远开多远
			printf("The maximum travel distance = %.2lf", maxdis);
			return 0;
		}
	}
	printf("%.2lf", totalPrice);
	return 0;
}