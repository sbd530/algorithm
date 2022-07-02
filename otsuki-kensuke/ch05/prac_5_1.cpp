/*
# 問題文
明日から太郎君の夏休みが始まります。 太郎君は夏休みの計画を立てることにしました。
夏休みは N 日からなります。 各 i (1≤i≤N) について、i 日目には太郎君は次の活動のうちひとつを選んで行います。
A: 海で泳ぐ。 幸福度 a(i)を得る。
B: 山で虫取りをする。 幸福度 b(i)を得る。
C: 家で宿題をする。 幸福度 c(i)を得る。
太郎君は飽き性なので、2日以上連続で同じ活動を行うことはできません。
太郎君が得る幸福度の総和の最大値を求めてください。

# 制約
入力はすべて整数である。
1 ≤ N ≤ 10^5
1 ≤ a(i) ,b(i) ,c(i) ≤ 10^4
*/
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}

int main() {
    int N;
    cin >> N;
    vector<vector<long long>> a(N, vector<long long>(3));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(3, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j == k) continue;
                chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < 3; ++i) {
        chmax(ans, dp[N][i]);
    }
    cout << ans << endl;
}