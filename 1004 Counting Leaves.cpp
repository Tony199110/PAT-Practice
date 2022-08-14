# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <iomanip>
# include <vector>
# include <algorithm>
using namespace std;

vector<int> v[100];  // 容器v存储树
int book[100], maxdepth = -1;  // book存答案，即每一层叶子节点的数量

void dfs(int index, int depth) {
    if (v[index].size() == 0) {  // 若当前节点没有孩子，则当前层叶子节点数量加1
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return;
    }
    // 若当前节点有孩子，则遍历其孩子节点
    for (int i = 0; i < v[index].size(); i++) {
        dfs(v[index][i], depth + 1);
    }
}

int main() {
    int N, M;  // N是树中节点的数量，M是树中非叶子节点的数量
    scanf("%d %d", &N, &M);  // cin >> N >> M;
    int K, node, c;  // node是非叶子节点的编号，K是该非叶子节点的孩子数量
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