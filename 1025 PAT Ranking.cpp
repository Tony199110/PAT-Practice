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

struct student {
	long long int id;
	int score, finrank, loca, locarank;
};

bool cmp1(student a, student b) {
	return a.score != b.score ? a.score > b.score : a.id < b.id;
}

int main() {
	int n, m;
	cin >> n;
	vector<student> fin;
	for (int i = 0; i < n; i++) {
		cin >> m;
		vector<student> v(m);
		for (int j = 0; j < m; j++) {
			scanf("%lld %d", &v[j].id, &v[j].score);
			v[j].loca = i + 1;  // Ϊ�����Ÿ�ֵ
		}
		sort(v.begin(), v.end(), cmp1);  // �Ȱ�����������
		v[0].locarank = 1;
		fin.push_back(v[0]);
		for (int j = 1; j < m; j++) {
			v[j].locarank = (v[j].score == v[j - 1].score) ? (v[j - 1].locarank) : (j + 1);  // ����������ṹ��
			fin.push_back(v[j]);  // ��ֵ���ܵ�����
		}
	}
	sort(fin.begin(), fin.end(), cmp1);  // �ٽ���������
	fin[0].finrank = 1;
	for (int j = 1; j < fin.size(); j++) {
		fin[j].finrank = (fin[j].score == fin[j - 1].score) ? (fin[j - 1].finrank) : (j + 1);  // ������������ṹ��
	}
	printf("%d\n", fin.size());  // ��ʼ���
	for (int i = 0; i < fin.size(); i++) {
		printf("%013lld %d %d %d\n", fin[i].id, fin[i].finrank, fin[i].loca, fin[i].locarank);
	}
	return 0;
}