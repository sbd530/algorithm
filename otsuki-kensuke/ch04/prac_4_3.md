# 4.3

피보나치 수열의 일반항이
$$ F_{N} = {1 \over \sqrt5}({({1 + \sqrt5 \over 2})^N - ({1 - \sqrt5 \over 2})^N}) $$
인 것을 증명하라.

## 풀이

피보나치 수열의 점화식은 다음과 같다.
$$ a_{n+2}-a_{n+1}-a_{n}=0\quad(1) $$
만약
$$ \alpha+\beta=1\space\cdots\space[A] ,\space\space \alpha \beta = -1 \space \cdots \space [B]  $$
를 만족하는 두 실수 알파와 베타가 존재한다면, 식(1)은 다음 식과 같이 변형된다.
$$ a_{n+2} - (\alpha+\beta) a_{n+1} + \alpha\beta a_{n} = 0\quad(2) $$
또한 식(2) 양변에 2를 곱하여 분리하면 다음과 같이 두 식으로 바꿀 수 있다.
$$
a_{n+2} - \alpha a_{n+1} = \beta (a_{n+1} - \alpha a_{n})\quad(3)
\\
a_{n+2} - \beta a_{n+1} = \alpha (a_{n+1} - \beta a_{n})\quad(4)
$$
식(3)은 등비수열의 형태를 띄고 있으므로 일반식으로 바꿀 수 있다.
$$
a_{n+2} - \alpha a_{n} = b_{n} 
$$
이 때
$$
b_{1} = 1 - \alpha = \beta
\\
b_{n+1} = \beta b_{n}
$$
라면
$$
a_{n+1} - \alpha a_{n} = \beta^n \quad (5)
$$
를 만족하며, 식(4)도 동일하게 다음과 같이 나타낼 수 있다.
$$
a_{n+1} - \beta a_{n} = \alpha^n \quad (6)
$$
알파와 베타값은 조건[A], 조건[B]를 만족하는 실수이므로 이차방정식
$$
x^2 - x - 1 = 0
$$
를 만족하는 두 실수해에 해당하므로 두 수는 다음과 같다.
$$
if \; \alpha \gt \beta, \; \alpha = {1 + \sqrt5\over2} , \; \beta = {1 - \sqrt5\over2}
$$
따라서 식(5)와 식(6)을 조합하여 실근을 대입하여 일반항을 구할 수 있다.
$$
(\alpha - \beta) a_{n} = \alpha ^ n - \beta ^ n
$$
$$
\therefore \; a_{n} = {1\over\sqrt5}({({1+\sqrt5\over2})^n - ({1-\sqrt5\over2})^n})
$$