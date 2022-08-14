# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);  // �����룬�߲�����O(n)�ĸ��Ӷ�
		temp = temp + v[i];  // ��ʱ���������ܺ�
		if (temp < 0) {  // ����ǰ�ܺ�С��0��ʹ�ܺ�����Ϊ0���±�Ϊ��һ��λ��
			temp = 0;
			tempindex = i + 1;
		}
		else if (temp > sum) {  // ����ǰ�ܺͱ���ˣ����������ܺ͡������±�
			sum = temp;
			leftindex = tempindex;
			rightindex = i;
		}
	}
	if (sum < 0) sum = 0;
	printf("%d %d %d", sum, v[leftindex], v[rightindex]);
	return 0;
}