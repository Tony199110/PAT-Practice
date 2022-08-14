# include <iostream>
# include <iomanip>
# include <vector>
using namespace std;

int N, M, C1, C2;  // N�ǽڵ�������M�Ǳ�������C1Ϊstart��C2Ϊend
int num_of_team[500]; // ���ÿ���ڵ��Ȩ�أ�����Ϊÿ�����еľ�Ԯ������
int dis[500][500]; // ��Žڵ�֮��ľ��룬����Ȩ
vector<int> v[500]; // ���������ڴ��ÿ���ڵ���ھ�
int mindis[500];  // ��¼���·��
int paths, teams;  // paths��ʾ������̵����·��������teams��ʾ���·�������ĵ�Ȩ֮��

// dfs������ȱ�����curcity��Ŀǰ���ڳ��У�curlen��Ŀǰ���߹��ľ��룬curteam��Ŀǰ·�������ĵ�Ȩ֮��
void dfs(int curcity, int curlen, int curteam) {
    if (curlen > mindis[curcity]) return;  // ����ߵľ����Ѿ�����֮ǰ��¼�����·�����ȣ�ֱ���˳�(����)
    if (curcity == C2) {  // ����Ŀ�ĵ�
        if (curlen == mindis[curcity]) {
            // �������·�����������·��������ͬ
            paths++;
            if (curteam > teams) teams = curteam;
        }
        else {
            // �������·����֮ǰ�����·������
            mindis[C2] = curlen;
            paths = 1;
            teams = curteam;
        }
    }
    else {  // δ����Ŀ�ĵ�
        if (curlen < mindis[curcity]) mindis[curcity] = curlen; // ���Ŀǰ�ľ�������·��Ҫ�̣������
        for (int i = 0; i < v[curcity].size(); i++) {
            int j = v[curcity][i];  // ������ǰ�ڵ���ھ�
            dfs(j, curlen + dis[curcity][j], curteam + num_of_team[j]);
        }
    }
}

int main() {
    int i, j, k, l;
    cin >> N >> M >> C1 >> C2;
    for (i = 0; i < N; i++) cin >> num_of_team[i];  // ����ڵ�Ȩ��
    for (i = 0; i < M; i++) {
        cin >> j >> k >> l;
        v[j].emplace_back(k);  // ��ͼ�����ӹ�ϵ�����ڽ�����
        v[k].emplace_back(j);  // ����Ϊ����ͼ
        dis[j][k] = dis[k][j] = l;
    }
    for (i = 0; i < N; i++) mindis[i] = 1000000;
    dfs(C1, 0, num_of_team[C1]);
    cout << paths << " " << teams;
    return 0;
}