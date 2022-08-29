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

# define lowbit(i) ((i) & (-i))
const int maxn = 100010;
int c[maxn];  // ��״���飻��ϣɢ�У��±�������������������Ӧ��������ĸ���
stack<int> s;
void update(int x, int v) {  // ������״����c��x��Ҫ�޸ĵ�����v��1���������x��v��-1�����ȥ��x
	for (int i = x; i < maxn; i += lowbit(i)) {  // �����forȥ�����������Ȼ���γ���һ����״����
		c[i] += v;
	}
}
int getsum(int x) {  // ͳ��С�ڵ���x�����ĸ���
	int sum = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {  // �����״����ĺô����ǿ��ԡ����š�ȥ�����ܴ����
		sum += c[i];
	}
	return sum;
}
void PeekMedian() {
	int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;  // ȥ�����kС����������һ����С����������λ��
	while (left < right) {  // ���ֲ���
		mid = (left + right) / 2;
		if (getsum(mid) >= k)
			right = mid;
		else
			left = mid + 1;
	}
	printf("%d\n", left);
	return;
	/*  // ��forֱ�ӱ������У��ᳬʱ
	for (int i = 1; i < maxn; i++) {
		if (getsum(i) == k) {
			printf("%d\n", i);
			return;
		}
	}*/
}

int main() {
	int n, temp;
	scanf("%d", &n);
	char str[15];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		if (str[1] == 'u') {  // push key
			scanf("%d", &temp);
			s.push(temp);
			update(temp, 1);  // ��״��������һ����
		}
		else if (str[1] == 'o') {  // pop
			if (s.empty()) {
				printf("Invalid\n");
			}
			else {
				update(s.top(), -1);  // ��״�������һ����
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else {  // peekMedian
			if (s.empty()) {
				printf("Invalid\n");
			}
			else {
				PeekMedian();
			}
		}
	}
	return 0;
}
