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

vector<int> v;
int cnt = 0;
void swap(int x) {
	int temp = v[0];
	v[0] = v[x];
	v[x] = temp;
	cnt++;
}
int main() {
	int n, temp, i = 0;
	bool sorted = false;
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		v[temp] = i;  // ��¼ÿ��Ԫ�ص�λ�ã�ĳ��Ԫ��temp�ڵ�i��λ��
	}
	while (!sorted) {
		if (v[0] == 0) {  // ��0��ǰ�ص����Լ���λ�ã��Ǿ�Ҫ��һ��δ�����������
			while (++i < n) {
				if (v[i] != i) {
					swap(i);  // ��i��0����
					break;
				}
			}
			if (i == n) sorted = true;  // �Ҳ���δ����ģ��Ǿͽ�����
		}
		else {  // �������
			swap(v[0]);  // �� 0��������λ�õ��±�ָ����� �� 0 ���н���
		}
	}
	printf("%d", cnt);
	return 0;
}

