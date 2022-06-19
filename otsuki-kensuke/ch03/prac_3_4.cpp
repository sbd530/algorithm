/*
N개의 정수 a(0),a(1),...,a(N-1)이 주어졌을 때 두 정수를 골라 뺄셈한 결과(차)가 최대인 값을 구하는 O(N) 복잡도 알고리즘을 설계하라.
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

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < N; ++i) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }

    long result;
    result = max - min;
    if (result < 0) result = -(result);
    cout << result << endl;
}