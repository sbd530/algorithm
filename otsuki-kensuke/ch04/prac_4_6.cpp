/*
부분합 문제에서 재귀 함수를 사용한 복잡도 O(2^N)의 코드 4-9에 대해 메모이제이션을 사용하여 O(NW) 복잡도로 개선하라.
*/
#include <iostream>
#include <vector>
using namespace std;

bool func_4_9(int i, int w, const vector<int> &a) {
    // 베이스 케이스
    if (i == 0) {
        if (w == 0) return true;
        else return false;
    }
    // a[i - 1]을 선택하지 않음
    if (func_4_9(i - 1, w, a)) return true;
    // a[i - 1]을 선택함
    if (func_4_9(i - 1, w - a[i - 1], a)) return true;
    // 둘 다 false라면 false
    return false;
}

// func(i, w)의 결과를 캐싱
// -1 : 미탐색, 0 : false, 1 : true
vector<vector<int>> cache;

int func(int i, int w, const vector<int> &a) {
    // base case
    if (i == 0) {
        if (w == 0) return 1;
        else return 0;
    }
    // check cache first
    if (cache[i][w] != -1) return cache[i][w];
    // a[i - 1]을 선택하지 않음
    if (func(i - 1, w, a)) return cache[i][w] = 1;
    // a[i - 1]을 선택함
    if (func(i - 1, w - a[i - 1], a)) return cache[i][w] = 1;
    // 둘 다 false라면 false
    return 0;
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    // bool result = func_4_9(N, W, a);

    cache.assign(N + 1, vector<int>(W + 1, -1));

    int result = func(N, W, a);

    if (result == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}