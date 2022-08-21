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

const int maxn = 200005;
int n1, n2, a1[maxn], a2[maxn], cnt = 0, i, j, ans;

int main() {
	scanf("%d", &n1);
	for (i = 1; i <= n1; i++) scanf("%d", &a1[i]);
	scanf("%d", &n2);
	for (i = 1; i <= n2; i++) scanf("%d", &a2[i]);
	int target = (n1 + n2 + 1) / 2;  // ��λ������λ�õ��±�
	i = 1, j = 1;
	while (i <= n1 && j <= n2) {
		ans = a1[i] <= a2[j] ? a1[i++] : a2[j++];  // �鲢��˼��
		if (++cnt == target) break;  // �ҵ���λ���Ϳ�������
	}
	if (i <= n1 && cnt < target) {  // a2�������˻�û�ҵ���λ��
		ans = a1[i + (target - (cnt + 1))];  // i��target�ĵ�λ���±꣬��cnt��ָ���ƶ���λ�ã���Ҫ+1����ƽ�ȵز���ǰ�ߵ�����
	}
	else if (j <= n2 && cnt < target) {
		ans = a2[j + (target - (cnt + 1))];
	}
	printf("%d", ans);
	return 0;
}