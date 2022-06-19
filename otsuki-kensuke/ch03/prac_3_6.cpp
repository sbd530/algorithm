/*
두 개의 양의 정수 K, N이 주어졌을 때 0 <= X, Y, Z <= K를 만족하는 정수 (X,Y,Z) 조합에서
X + Y + Z = N을 만족하는 경우가 얼마나 존재하는지 구하는 O(N^2) 복잡도 알고리즘을 설계하라.
*/
#include <iostream>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    
    // X + Y + Z = N
    // x + y + z = N -> O(N^3) -> X
    // Z = N - x - y -> 0 <= Z <= K 를 만족하는지 확인. -> O(N^2)
    int cnt = 0;

    for (int x = 0; x <= min(K, N); ++x) {
        for (int y = 0; y <= min(K, N); ++y) {
            int Z = N - x - y;
            if (Z >= 0 && Z <= K) ++cnt;
        }
    }

    cout << cnt << endl;
}
