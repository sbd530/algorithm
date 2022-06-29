/*
10진수 표기로 각 자리수가 7, 5, 3 중 하나 이고 7, 5, 3이 모두 한번은 등장하는 정수를 '753수'라고 부르기로 하자.
양의 정수 K가 주어졌을 때 K이하의 753수가 몇 개 존재하는지 구하는 알고리즘을 설계하라.
단, K의 자릿수를 d라고 할 때 O(3^d) 복잡도가 허용 범위다.
*/
#include <iostream>
using namespace std;

long long counter = 0;

int func(long long N, long long cur, int bin) {
    // 베이스 케이스
    if (cur > N) return;
    // 753이 모두 등장
    if (bin == 0b111) ++counter;
    // 자리수를 높이고 7,5,3을 일의 자리수에 붙이고, 753수 체크용 bin 변수를 바꾼다.
    func(N, cur * 10 + 7, bin | 0b001);
    func(N, cur * 10 + 5, bin | 0b010);
    func(N, cur * 10 + 3, bin | 0b100);
}

int main() {
    int K;
    cin >> K;
    func(K, 0, 0);
    cout << counter << endl;
}