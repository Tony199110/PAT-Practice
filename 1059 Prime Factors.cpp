# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <set>
# include <stack>
# include <algorithm>
# include <string>
# include <cstring>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

// �����ӵĴ洢
struct Factor {
	int x;  // ������
	int c;  // count��������Ŀ
} fac[20];  // ����int���͵ģ�ǰ10�������ͳ�����int��Χ
int k = 0;  // �����Ӹ���

// ������ ��ʽɸ��
const int maxn = 50000;
int prime[maxn];  // ������
int p[maxn];  // ��p[i]��i������
int num = 0;  // ��������

void prime_find() {  // һ��������δ�ŵ�������д��
	for (int i = 2; i < maxn; i++) {
		if (p[i] == 1) continue;  // i������������һ����
		prime[num++] = i;
		for (int j = 2 * i; j < maxn; j += i)
			p[j] = 1;  // ����ǰ���������б�����Ϊ������
	}
}

void factorization2(int n) {  // �����ӷֽ�
	for (int i = 0; n > 1; i++) {
		if (n % prime[i] == 0) {  // �����һ������prime[i]��n������
			fac[k].x = prime[i];  // �������������
			fac[k].c = 0;  // ����ʼ�������Ϊ0
			while (n % prime[i] == 0) {  // ����ȥ������������ӣ�ֱ��������
				fac[k].c++;  // ��¼��������ӵĸ���
				n /= prime[i];
			}
			k++;  // ��¼�����ӵ�����k
		}
	}
}

int main() {
	prime_find();  // ��ȡ������
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("1=1");
		return 0;
	}
	factorization2(n);
	printf("%d=", n);
	for (int i = 0; i < k; i++) {
		if (i != 0) printf("*");
		printf("%d", fac[i].x);
		if (fac[i].c > 1) {
			printf("^%d", fac[i].c);
		}
	}
	return 0;
}
