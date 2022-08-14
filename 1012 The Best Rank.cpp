# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

struct node {
	int id, best;  // best��rank��С���±�
	int score[4], rank[4];
}stu[2001];

int exist[1000000] = { 0 }, flag = -1;
bool cmp1(node a, node b) {
	return a.score[flag] > b.score[flag];
}

int main() {
	int n, m, id;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
		stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
	}
	for (flag = 0; flag <= 3; flag++) {
		sort(stu, stu + n, cmp1);  // �Ӵ�С�ţ�����ͨ��flagѭ����A��C��M��E������
		stu[0].rank[flag] = 1;
		for (int i = 1; i < n; i++) {  // �������rank
			stu[i].rank[flag] = i + 1;
			if (stu[i].score[flag] == stu[i - 1].score[flag]) {  // ���ͬ��
				stu[i].rank[flag] = stu[i - 1].rank[flag];  // ͬ����rankȡ��ͬ����ȡ�ǰ�Ǹ�
			}
		}
	}
	for (int i = 0; i < n; i++) {
		exist[stu[i].id] = i + 1;  // ��sort֮���ٸ�exist��ֵ����������ֵ���±����stu
		stu[i].best = 0;
		int minn = stu[i].rank[0]; // ���ÿ��ѧ�������rank��������Сֵ
		for (int j = 1; j <= 3; j++) {
			if (stu[i].rank[j] < minn) {
				minn = stu[i].rank[j];
				stu[i].best = j;
			}
		}
	}
	char c[5] = { "ACME" };
	for (int i = 0; i < m; i++) {
		cin >> id;
		int temp = exist[id]; // ��idΪ�±꣬�������һһӳ��Ĺ�ϵ
		if (temp) {
			int best = stu[temp - 1].best;
			printf("%d %c\n", stu[temp - 1].rank[best], c[best]);
		}
		else {
			printf("N/A\n");
		}
	}
	return 0;
}