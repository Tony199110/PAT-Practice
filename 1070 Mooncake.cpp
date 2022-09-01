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

struct mooncake {
	float num, price, unit;
};
bool cmp1(mooncake a, mooncake b) {
	return a.unit > b.unit;  // sort默认升序，所以这里整个降序的
}
int main() {
	int n, need;
	scanf("%d %d", &n, &need);
	vector<mooncake> v(n);
	for (int i = 0; i < n; i++) scanf("%f", &v[i].num);
	for (int i = 0; i < n; i++) scanf("%f", &v[i].price);
	for (int i = 0; i < n; i++) v[i].unit = v[i].price / v[i].num;
	sort(v.begin(), v.end(), cmp1);
	float result = 0.0;
	for (int i = 0; i < n; i++) {
		if (v[i].num <= need)
			result += v[i].price;
		else {
			result += v[i].unit * need;
			break;
		}
		need -= v[i].num;
	}
	printf("%.2f", result);
	return 0;
}

