/*
N개의 양의 정수 a(0),a(1),...,a(N-1)에서 몇 개를 골라 총합이 W가 될 수 있는지 여부를 판정하는 문제를 O(NW) 복잡도로 푸는 알고리즘을 설계하라.
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
            if (dp[i][j]) 
                dp[i + 1][j] = true;
            
            if (j >= a[i] && dp[i][j - a[i]])
                dp[i + 1][j] = true;
        }
    }
    if (dp[N][W]) cout << "Y" << endl;
    else cout << "N" << endl;
}

/*
6 9
7 4 1 6 5 10
*/