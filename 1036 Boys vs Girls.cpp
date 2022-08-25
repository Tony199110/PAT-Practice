# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <set>
# include <algorithm>
# include <string>
# include <cstring>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	string female, male;
	int fscore = -1, mscore = 101;
	for (int i = 0; i < n; i++) {
		string name, sex, id;
		int score;
		cin >> name >> sex >> id >> score;
		if (sex == "F") {
			if (score > fscore) {
				fscore = score;
				female = name + " " + id;
			}
		}
		else if (sex == "M") {
			if (score < mscore) {
				mscore = score;
				male = name + " " + id;
			}
		}
	}
	if (fscore != -1) cout << female << endl;
	else cout << "Absent" << endl;
	if (mscore != 101) cout << male << endl;
	else cout << "Absent" << endl;
	if (fscore != -1 && mscore != 101) cout << fscore - mscore << endl;
	else cout << "NA";
	return 0;
}