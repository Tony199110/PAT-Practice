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

vector<int> post, in;
map<int, int> level;  // map������ģ����Լ������index��С��������

void pre(int root, int start, int end) {  // ��֪�����������ǰ��ĺ�����root�ǶԺ���˵�ģ�start��end�Ƕ�����˵��
	if (start > end) return;
	int i = start;
	while (i < end && in[i] != post[root]) i++;
	printf("%d ", post[root]);
	pre(root - (end - i) - 1, start, i - 1);  // post�еĸ��ڵ��±��ȥ���������ȣ��ټ�ȥ���ĳ���1���������������ȣ�Ҳ������ڵ���±�
	pre(root - i, i + 1, end);
}

void pre2(int root, int start, int end, int index) {  // ��֪��������������ĺ���������pre�޸Ķ���
	if (start > end) return;
	int i = start;
	while (i < end && in[i] != post[root]) i++;
	level[index] = post[root];  // index��ʾ��ǰ�ڵ��ڶ�����������Ӧ���±�
	pre2(root - (end - i) - 1, start, i - 1, 2 * index + 1);
	pre2(root - 1, i + 1, end, 2 * index + 2);
}

int main() {
	int n;
	scanf("%d", &n);
	post.resize(n);  // ����push_back��ʼ��vector���Ͳ���Ҫresize������С
	in.resize(n);  // ��Ϊ����2�������±���ʳ�ʼ��vector�ģ����Ա���Ҫresizeָ�����С�����򱨴�
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);  
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	pre2(n - 1, 0, n - 1, 0);
	auto it = level.begin();
	printf("%d", it->second);
	while (++it != level.end()) printf(" %d", it->second);
	return 0;
}