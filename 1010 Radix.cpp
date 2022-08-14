# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
using namespace std;

long long convert(string n, long long radix) { // 将数值n按照radix进制转化为10进制表示的数
	long long sum = 0;  // 由于返回值是long long，当radix较大时容易溢出，变成负数
	int temp = 0;
	for (int i = 0; i < n.length(); i++) {
		temp = isdigit(n[i]) ? n[i] - '0' : n[i] - 'a' + 10;  // 分两段考虑字符转数值
		sum += temp * pow(radix, n.length() - i - 1);
	}
	/*
	int index = 0;  // 使用string中的rbegin()和rend()函数来反向遍历字符串
	for (auto it = n.rbegin(); it != n.rend(); it++){
		temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
		sum += temp * pow(radix, index++);
	}
	*/
	return sum;
}

long long find_radix(string n, long long num) {
	char it = *max_element(n.begin(), n.end());
	long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
	long long high = max(low, num);  // low有可能大于num，例如n为0，num为0
	while (low <= high) {
		long long mid = (low + high) / 2;  // 二分查找
		long long t = convert(n, mid);
		if (t < 0 || t > num) { // 将n转换为十进制数时，由于num可以较大(10^18),convert后long long可能会溢出，变成负数
			high = mid - 1;
		}
		else if (t == num) return mid;
		else low = mid + 1;
	}
	return -1;
}

int main() {
	string n1, n2;
	long long tag = 0, radix = 0, result_radix;
	cin >> n1 >> n2 >> tag >> radix;
	result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
	if (result_radix != -1) printf("%lld", result_radix);
	else printf("Impossible");
	return 0;
}