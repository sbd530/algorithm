/*
N개의 양의 정수 a(0),a(1),...,a(N-1)에서 몇 개를 골라 총합이 1이상 W 이하인 정수가 몇 개 존재하는지 O(NW) 복잡도로 구하는 알고리즘을 설계하라.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    
    vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));

    // 초기 조건
    dp[0][0] = true;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (!dp[i][j]) continue;
            
            dp[i + 1][j] = true;

            if (j + a[i] <= W) dp[i + 1][j + a[i]] = true;    
        }
    }

    int ans = 0;
    for (int j = 0; j <= W; ++j) {
        if (dp[N][j]) ++ans;
    }
    cout << ans << endl;
}
