/*
깊이 우선 탐색
*/
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(const Graph &G, int v) {
    // v는 이미 방문했음으로 처리
    seen[v] = true;

    // v에서 갈 수 있는 각 버텍스 nex_v에 대하여
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 탐색 : 초기상태 미방문
    seen.assign(N, false);
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue;
        dfs(G, v);
    }
}