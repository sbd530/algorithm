#include <iostream>
#include <vector>
using namespace std;
const int INF = 200000000;

// 선형 탐색 예4 : 쌍의 합의 최소값
// 시간 복잡도 : O(N^2)
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(K);
    for (int i = 0; i < N; ++i) cin >> a[i];    
    for (int i = 0; i < N; ++i) cin >> b[i];    

    // Linear search
    int min = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i] + b[j] < K) continue;
            if (a[i] + b[j] < min) min = a[i] + b[j]; 
        }
    }

    cout << min << endl;
}
