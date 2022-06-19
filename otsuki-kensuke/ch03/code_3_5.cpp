/*
>> 부분합 문제
  N개 양의 정수 a(0),a(1),...,a(N-1)과 양의 정수 W가 주어졌을 때
  a(0),a(1),...,a(N-1)에서 정수를 몇 개 골라 그 합이 W가 될 수 있는지 판정하라.

N개 요소의 부분집합 개수 = 2^N 개
-> 부분집합의 전체탐색의 시간복잡도는 O(2^N)
부분집합은 2진법 N 자릿수로 표현가능
-> {a(0),a(1),a(2),a(3)} 중 {a(1),a(2)}
-> 0110
2진수 2^N 개를 십진수의 i로 매핑하고 1을 i만큼 시프팅하여, 
그 수가 2진수에 포함되는지 확인한다.
-> if (bit & (1 << i)) {}
-> i는 2진수의 길이 N만큼 탐색하므로 시간 복잡도는 O(N)
부분합을 탐색하는 시간복잡도는 O(N*2^N)
*/


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    bool exist = false;
    // 0 <= bit < 2^N
    for (int bit = 0; bit < (1 << N); ++bit) {
        int sum = 0;
        
        for (int i = 0; i < N; ++i) if (bit & (1 << i)) sum += a[i];
        
        if (sum == W) { exist = true; break; }
    }

    if (exist) cout << "yes" << endl;
    else cout << "no" << endl;
}