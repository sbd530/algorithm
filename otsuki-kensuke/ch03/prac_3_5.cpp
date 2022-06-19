/*
N개의 양의 정수 a(0),a(1),...,a(N-1)이 주어졌을 때 N개의 정수가 모두 짝수라면 2로 나눈 값으로 치환하는 작업을 더 이상 할 수 없을 때까지 반복한다.
이런 작업을 몇 번해야 하는지 구하는 알고리즘을 설계하라.
*/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> cnt(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 각 숫자들(a[i])이 2로 최대 몇 번까지 나눠지는지 (cnt[i]) 구한다.
    for (int i = 0; i < N; ++i) {
        while (!(a[i] & 1)) { // 홀수일 때까지
            a[i] = a[i] >> 1;
            cnt[i] += 1;
        }
    }

    // cnt[i] 의 최소값을 구한다.
    int min_cnt = INT_MAX;
    for (int i = 0; i < N; ++i) {
        if (cnt[i] < min_cnt) min_cnt = cnt[i];
    }

    cout << min_cnt << endl;
}

/*
시간복잡도 평가
모든 N개의 정수들 탐색 -> O(N)
각각의 정수마다 홀수가 될 때까지 시프트 -> int로 전제하였으므로 O(32) -> O(1) -> 만약 타입 크기가 k byte라면 O(k)
따라서 O(kN)
*/
