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

int in[1010], level[1010], n, t = 0;
void inOrder(int root) {  // ���������ֻ����������������ôд���������������ɸ����±�õ��������������±�
	if (root >= n) return;
	inOrder(root * 2 + 1);  // ��
	level[root] = in[t++];  // ����root�ǰ��ղ�������Ĵ��ϵ��¡������ҵ�˳���ŵģ����������ĸ��ڵ�ı��Ϊ0��t�����������ʵʵ���ڵر���ÿһ���ڵ�
	inOrder(root * 2 + 2);  // ��
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	sort(in, in + n);
	inOrder(0);
	printf("%d", level[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", level[i]);
	return 0;
}
