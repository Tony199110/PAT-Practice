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

struct node {
	string name;
	int month, day, hour, minute, status, time;  // time�ǻ��㵽0:00:00�ķ����������ȴ�С�õ�
};

bool cmp1(node a, node b) {
	return a.name != b.name ? a.name < b.name : a.time < b.time;
}

double billFromZero(node call, int* rate) {  // �������㵽0:00:00�ĵ绰����
	double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
	for (int i = 0; i < call.hour; i++) {
		total += rate[i] * 60;
	}
	return total / 100.0;
}

int main() {
	int rate[25] = { 0 }, n;
	for (int i = 0; i < 24; i++) {
		cin >> rate[i];
		rate[24] += rate[i];  // ��һ����绰�ķ���
	}
	cin >> n;
	vector<node> data(n);  // n��call record
	for (int i = 0; i < n; i++) {
		cin >> data[i].name;
		scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
		string temp;
		cin >> temp;
		data[i].status = (temp == "on-line") ? 1 : 0;
		data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;  // �Ե������Ϊ��׼��������׼��ʱ��
	}  // ���ˣ��������
	// ��n��call record�Ȱ������������ٰ���ʱ��������������ʱǰ������������ͬ��״̬����Ϊ1��0�ľ��Ǻϸ�����
	sort(data.begin(), data.end(), cmp1);
	map<string, vector<node>> custom;
	for (int i = 1; i < n; i++) {
		if (data[i].name == data[i - 1].name && data[i - 1].status == 1 && data[i].status == 0) {  // ����Գɹ�
			custom[data[i - 1].name].push_back(data[i - 1]);
			custom[data[i].name].push_back(data[i]);  // ����һͨ�绰��2����¼���������ŵ�map��
		}
	}  // ���ˣ������ɣ����Խ��������
	for (auto it : custom) {  // ����map
		vector<node> temp = it.second;  // ��һ���˽������
		cout << it.first;
		printf(" %02d\n", temp[0].month);
		double total = 0.0;
		for (int i = 1; i < temp.size(); i += 2) {  // һ��һ�����
			double t = billFromZero(temp[i], rate) - billFromZero(temp[i - 1], rate);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
			total += t;
		}
		printf("Total amount: $%.2lf\n", total);
	}
	return 0;
}