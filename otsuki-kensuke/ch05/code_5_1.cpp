#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60

int main() {
    int N; cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 배열 dp를 정의(배열 전체를 무한대를 의미하는 값으로 초기화)
    vector<long long> dp(N, INF);

    // 초기 조건
    dp[0] = 0;

    // 반복
    for (int i = 1; i < N; ++i) {
        if (i == 1) {
            dp[i] = abs(h[i] - h[i - 1]);
        } else {
            long long oneStep = dp[i - 1] + abs(h[i] - h[i - 1]);
            long long twoStep = dp[i - 2] + abs(h[i] - h[i - 2]);
            dp[i] = min(oneStep, twoStep);
        } 
    }

    cout << dp[N - 1] << endl;
}