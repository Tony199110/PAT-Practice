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
		title[ttitle].insert(id);  // 将多个id放入集合，与要被查询的title映射
		getline(cin, tauthor);
		author[tauthor].insert(id);
		while (cin >> tkey) {
			key[tkey].insert(id);  // 关键词可以有多个，分开再与id映射
			char c = getchar();  // 可能读到空格或回车
			if (c == '\n') break;  // 若是空格，则继续
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
		cout << num << ": " << temp << endl;  // 这里不能用printf，string类型的temp会乱码
		if (num == 1) query(title, temp);
		else if (num == 2) query(author, temp);
		else if (num == 3) query(key, temp);
		else if (num == 4) query(pub, temp);
		else if (num == 5) query(year, temp);
	}
	return 0;
}