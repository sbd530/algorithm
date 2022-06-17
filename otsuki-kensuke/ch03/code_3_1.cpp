#include <iostream>
#include <vector>
using namespace std;

// 선형 탐색 예1
// 시간 복잡도 : O(N)
int main() {
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // Linear search
    bool exist = false; // init value -> false
    for (int i = 0; i < N; ++i) if (a[i] == v) exist = true; // 발견시 플래그 설정

    // result print
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
