/*
"12324" 처럼 모든 글자가 1 이상 9 이하의 숫자로 된 길이가 N인 문자열 S가 주어졌을 때
문자 사이사이에 +를 넣을 수 있다고 하자.
+는 0개 이상 가능하나 연속한 +는 넣을 수 없다.
이런 조건으로 만들 수 있는 모든 문자열으 산술식으로 보고 총합을 계산하는 O(N2^N) 복잡도 알고리즘을 설계하라.
예) S = "125" -> (125) + (1 + 25), (12 + 5), (1 + 2 + 5) -> 176
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    long long ans = 0;

    for (int bit = 0; bit < (1 << (N-1)); ++bit) {
        long long temp = 0;
        for (int i = 0; i < N - 1; ++i) {
            temp *= 10;
            temp += S[i] - '0';

            if (bit & (1 << i)) {
                ans += temp;
                temp = 0;
            }
        }

        temp *= 10;
        temp += S.back() - '0';
        ans += temp;
    }

    cout << ans << endl;
}
