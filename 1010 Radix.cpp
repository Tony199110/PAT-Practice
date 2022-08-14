# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
using namespace std;

long long convert(string n, long long radix) { // ����ֵn����radix����ת��Ϊ10���Ʊ�ʾ����
	long long sum = 0;  // ���ڷ���ֵ��long long����radix�ϴ�ʱ�����������ɸ���
	int temp = 0;
	for (int i = 0; i < n.length(); i++) {
		temp = isdigit(n[i]) ? n[i] - '0' : n[i] - 'a' + 10;  // �����ο����ַ�ת��ֵ
		sum += temp * pow(radix, n.length() - i - 1);
	}
	/*
	int index = 0;  // ʹ��string�е�rbegin()��rend()��������������ַ���
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
	long long high = max(low, num);  // low�п��ܴ���num������nΪ0��numΪ0
	while (low <= high) {
		long long mid = (low + high) / 2;  // ���ֲ���
		long long t = convert(n, mid);
		if (t < 0 || t > num) { // ��nת��Ϊʮ������ʱ������num���Խϴ�(10^18),convert��long long���ܻ��������ɸ���
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