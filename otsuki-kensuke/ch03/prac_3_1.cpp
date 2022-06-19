#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    int found_id = -1; // 존재하지 않는 값으로 초기화
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) {
            found_id = i; // 발견하면 인덱스 저장
        }
    }
}