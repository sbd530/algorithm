#include <iostream>
#include <vector>
using namespace std;

/*
그래프에서 노드 u에서 노드 v로 전이하는 변이 있고 그 전이 비용이 c일 때,
chmin(dp[v], dp[u] + c)
로 표현하고, 이런 처리를 그 변에 대한 완화라고 한다.
*/

template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

const long long INF = 1LL << 60

int main() {
    int N; cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 초기화(최소화 문제이므로 무한대로 초기화)
    vector<long long> dp(N, INF);

    // 초기 조건
    dp[0] = 0;

    // 반복
    for (int i = 1; i < N; ++i) {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 1) chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]);
    }

    cout << dp[N - 1] << endl;
}