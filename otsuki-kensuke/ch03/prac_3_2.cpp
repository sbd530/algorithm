/*
N개 정수 a(0),a(1),...,a(N-1)에서 정수 v가 몇 개 포함되는지 구하는 O(N) 복잡도 알고리즘을 설계하라.
*/
#include <iostream>
using namespace std;

int main() {
    int N, v;
    cin >> N >> v;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == v) count += 1;
    } 

    cout << count << endl;
}