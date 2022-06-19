/*
N(>=2)개의 서로 다른 정수 a(0),a(1),...,a(N-1)이 주어졌을 때 두 번째로 작은 값을 구하는 O(N) 복잡도 알고리즘을 설계하라.
*/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int N;
    // cin >> N;
    N = 100;
    vector<int> a(N);
    // for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) a[i] = 1000 - i;

    int min_first = INT_MAX;
    int min_second = INT_MAX;

    for (int i = 0; i < N; ++i) {
        if (a[i] > min_second)
            continue;
        else if (a[i] < min_first) {
            min_second = min_first;
            min_first = a[i];
        } else if (a[i] > min_first && a[i] < min_second) 
            min_second = a[i];
    }

    cout << min_second << endl;
}