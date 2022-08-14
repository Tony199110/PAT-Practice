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
		scanf("%d", &v[i]);  // 边输入，边操作，O(n)的复杂度
		temp = temp + v[i];  // 临时的子序列总和
		if (temp < 0) {  // 若当前总和小于0，使总和重新为0，下标为下一个位置
			temp = 0;
			tempindex = i + 1;
		}
		else if (temp > sum) {  // 若当前总和变大了，则更新最大总和、左右下标
			sum = temp;
			leftindex = tempindex;
			rightindex = i;
		}
	}
	if (sum < 0) sum = 0;
	printf("%d %d %d", sum, v[leftindex], v[rightindex]);
	return 0;
}