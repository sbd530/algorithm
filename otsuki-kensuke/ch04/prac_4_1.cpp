/* 4.1
트리보나치 수열은 다음과 같이 정의된 수열이다.
T(0) = 0
T(1) = 0
T(2) = 1
T(N) = T(N-1) + T(N-2) + T(N-3) (N=3,4,...)
0,0,1,1,2,4,7,13,24,44,...로 이어질 때 트리보나치 수열의 제 N항 값을 구하는 재귀함수를 설계하라.
*/
#include <iostream>
using namespace std;

int base(int m) {
    if (m == 2) return 1;
    return 0;
}

int func(int n) {
    // base case
    if (n < 3) return base(n);

    return func(n - 3) + func(n - 2) + func(n - 1);
}

int main() {
    int N;
    cin >> N;

    int ans = func(N);

    cout << ans << endl;
}