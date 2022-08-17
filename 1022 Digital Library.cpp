# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <set>
# include <algorithm>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdio>
using namespace std;

map<string, set<int>> title, author, key, pub, year;

void query(map<string, set<int>>& m, string& str) {
	if (m.find(str) != m.end()) {
		for (auto it = m[str].begin(); it != m[str].end(); it++) {
			printf("%07d\n", *it);
		}
	}
	else {
		printf("Not Found\n");
	}
}

int main() {
	int n, m, id, num;
	scanf("%d", &n);
	string ttitle, tauthor, tkey, tpub, tyear;
	for (int i = 0; i < n; i++) {
		scanf("%d\n", &id);
		getline(cin, ttitle);
		title[ttitle].insert(id);  // �����id���뼯�ϣ���Ҫ����ѯ��titleӳ��
		getline(cin, tauthor);
		author[tauthor].insert(id);
		while (cin >> tkey) {
			key[tkey].insert(id);  // �ؼ��ʿ����ж�����ֿ�����idӳ��
			char c = getchar();  // ���ܶ����ո��س�
			if (c == '\n') break;  // ���ǿո������
		}
		getline(cin, tpub);
		pub[tpub].insert(id);
		getline(cin, tyear);
		year[tyear].insert(id);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d: ", &num);
		string temp;
		getline(cin, temp);
		cout << num << ": " << temp << endl;  // ���ﲻ����printf��string���͵�temp������
		if (num == 1) query(title, temp);
		else if (num == 2) query(author, temp);
		else if (num == 3) query(key, temp);
		else if (num == 4) query(pub, temp);
		else if (num == 5) query(year, temp);
	}
	return 0;
}