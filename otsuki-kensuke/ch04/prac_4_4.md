# 4.4

```cpp
int fibo(int N) {
    if (N == 0) return 0;
    else if (N == 1) return 1;

    return fibo(N - 1) + fibo(N - 2);
}
```

위 코드의 알고리즘 복잡도가
$$
O(({1+\sqrt5\over2})^N)
$$
인 것을 증명하라.

## 풀이

연습문제 4.3 풀이에서 피보나치 수열의 일반항이
$$
F_{N} = {1\over\sqrt5}({({1+\sqrt5\over2})^N - ({1-\sqrt5\over2})^N})
$$
인 것을 증명하였다.

복잡도 평가를 위해 일반항의 극한값을 구하면
$$
\displaystyle\lim_{N\rarr\infin}{F_{N}} = {1\over\sqrt5}({1+\sqrt5\over2})^N
$$

가 된다. 따라서 상수곱을 제거한 복잡도는 $ O(({1+\sqrt5\over2})^N) $ 가 된다.