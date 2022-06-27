/* 4.2
연습문제 4.1에서 설계한 재귀 함수에 대해 메모이제이션을 사용해서 효율을 개선하라.
그리고 메모이제이션 실시 후의 복잡도를 평가하라.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> cache;

int func_memo(int n) {
    if (cache[n] != -1) return cache[n];

    return cache[n] = func_memo(n - 3) + func_memo(n - 2) + func_memo(n - 1);
}

int main() {
    int N;
    cin >> N;
    cache.assign(N + 1, -1);
    cache[0] = 0;
    if (N >= 1) cache[1] = 0;
    if (N >= 2) cache[2] = 1;

    int ans = func_memo(N);

    cout << ans << endl;
}

/*
시간복잡도 평가
입력 받는 수 N
벡터 배열의 하나의 메모리 값을 읽는 시간 : k = Const
3개의 정수를 더하는 평균적인 시간 : l = Const
O(3k*l*N) = O(l*N) = O(N)
*/