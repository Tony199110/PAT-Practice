# include <iostream>
# include <iomanip>
# include <vector>
using namespace std;

int N, M, C1, C2;  // N是节点数量，M是边数量，C1为start，C2为end
int num_of_team[500]; // 存放每个节点的权重，本题为每个城市的救援队数量
int dis[500][500]; // 存放节点之间的距离，即边权
vector<int> v[500]; // 该容器用于存放每个节点的邻居
int mindis[500];  // 记录最短路径
int paths, teams;  // paths表示并列最短的最短路径数量，teams表示最短路径经过的点权之和

// dfs深度优先遍历，curcity是目前所在城市，curlen是目前的走过的距离，curteam是目前路径经过的点权之和
void dfs(int curcity, int curlen, int curteam) {
    if (curlen > mindis[curcity]) return;  // 如果走的距离已经大于之前记录的最短路径长度，直接退出(返回)
    if (curcity == C2) {  // 到达目的地
        if (curlen == mindis[curcity]) {
            // 如果这条路径长度与最短路径长度相同
            paths++;
            if (curteam > teams) teams = curteam;
        }
        else {
            // 如果该条路径比之前的最短路径更短
            mindis[C2] = curlen;
            paths = 1;
            teams = curteam;
        }
    }
    else {  // 未到达目的地
        if (curlen < mindis[curcity]) mindis[curcity] = curlen; // 如果目前的距离比最短路径要短，则更新
        for (int i = 0; i < v[curcity].size(); i++) {
            int j = v[curcity][i];  // 遍历当前节点的邻居
            dfs(j, curlen + dis[curcity][j], curteam + num_of_team[j]);
        }
    }
}

int main() {
    int i, j, k, l;
    cin >> N >> M >> C1 >> C2;
    for (i = 0; i < N; i++) cin >> num_of_team[i];  // 输入节点权重
    for (i = 0; i < M; i++) {
        cin >> j >> k >> l;
        v[j].emplace_back(k);  // 将图的连接关系存入邻接链表
        v[k].emplace_back(j);  // 此题为无向图
        dis[j][k] = dis[k][j] = l;
    }
    for (i = 0; i < N; i++) mindis[i] = 1000000;
    dfs(C1, 0, num_of_team[C1]);
    cout << paths << " " << teams;
    return 0;
}