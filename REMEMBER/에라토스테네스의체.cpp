/*
에라토스테네의 체는 소수(Prime Number)를 찾는 방법이다. 대량의 소수들을 구해야 할 때
아주 유용한 알고리즘으로 O(N^1/2)의 시간 복잡도를 갖는다.

원리
- 소수란 약수가 오로지 1인 수이다. 즉, 1을 제외한 수의 배수가 되는 수는 소수가 아니다.
에라토스테네의 체는 이러한 소수의 개념을 이용한 알고리즘이다.
임의의 수 n 까지의 소수를 구하고자 할 때 2부터 n의 제곱근까지 돌며 모든 배수들을 소수에서
제외시키는 방식이다.
*/

#include <iostream>
#include <cmath>

using namespace std;

int number = 71; // 구하고자 하는 소수의 범위
int primeNum[72];

void primeNumberSieve()
{

    // primeNum 배열 초기화
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        // primeNum[1]가 0이면 이미 소수가 아니므로 continue
        if (primeNum[i] == 0)
            continue;
        // i*k (k < i) 까지의 수는 이미 검사했으므로 j는 i * i 부터 검사해준다.
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }

    // 소수 출력
    for (int i = 2; i <= number; i++)
    {
        if (primeNum[i] != 0)
        {
            printf("%d\n", primeNum[i]);
        }
    }
}

int main()
{
    primeNumberSieve();
}