# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <iomanip>
# include <vector>
# include <algorithm>
using namespace std;

vector<int> v[100];  // ����v�洢��
int book[100], maxdepth = -1;  // book��𰸣���ÿһ��Ҷ�ӽڵ������

void dfs(int index, int depth) {
    if (v[index].size() == 0) {  // ����ǰ�ڵ�û�к��ӣ���ǰ��Ҷ�ӽڵ�������1
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return;
    }
    // ����ǰ�ڵ��к��ӣ�������亢�ӽڵ�
    for (int i = 0; i < v[index].size(); i++) {
        dfs(v[index][i], depth + 1);
    }
}

int main() {
    int N, M;  // N�����нڵ��������M�����з�Ҷ�ӽڵ������
    scanf("%d %d", &N, &M);  // cin >> N >> M;
    int K, node, c;  // node�Ƿ�Ҷ�ӽڵ�ı�ţ�K�Ǹ÷�Ҷ�ӽڵ�ĺ�������
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &node, &K);  // cin >> ID_idx >> K;
        for (int j = 0; j < K; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    dfs(1, 0);
    printf("%d", book[0]);
    for (int i = 1; i <= maxdepth; i++) {
        printf(" %d", book[i]);
    }
    return 0;
}