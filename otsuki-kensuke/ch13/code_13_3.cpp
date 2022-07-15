/*
너비 우선 탐색을 통한 최단 경로 알고리즘
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

// 입력 : 그래프 G의 탐색 시작점 s;
// 출력 : s에서 각 꼭짓점을 향한 최단 경로 거리를 나타내는 배열
vector<int> bfc(const Graph &G, int s) {
    int N = (int)G.size(); // 버텍스 개수
    vector<int> dist(N, -1); // 전체를 미방문으로 초기화
    queue<int> q;

    // 초기 조건
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int x : G[v]) {
            if (dist[x] != -1) continue;

            dist[x] = dist[v] + 1;
            q.push(x);
        }
    }

    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        // 무향 그래프
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist = bfs(G, 0);

    for (int v = 0; v < N; ++v) {
        cout << v << ": " << dist[v] << endl;
    }
}