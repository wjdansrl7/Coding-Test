/**
 * @file 9471.cpp
 * @author moonGi (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-27
 *
 * 이 문제는 피보나치 수열과 관련이 있음.
 * S4 - 피사노 주기
 * 피보나치 수열을 m으로 나누는 나머지가 주기를 이룬다는 것을 증명하는 문제이다.
 * Wall은 아래와 같은 여러 가지 성질도 증명했다.
 * m > 2인 경우에 k(m)은 짝수이다.
 * 임의의 짝수 정수 n > 2에 대해서, k(m) = n인 m이 항상 존재한다.
 * k(m) ≤ m^2 - 1
 * k(2n) = 3×2^(n-1)
 * k(5n) = 4×5^n
 * k(2×5n) = 6n
 * n > 2라면, k(10^n) = 15×10^(n-1)
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p;
    cin >> p;

    int n, m;

    int m1 = 0, m2 = 1;

    for (int i = 1; i <= p; i++)
    {
        int cnt = 2;
        cin >> n >> m;

        while (1)
        {
            int temp = m1;
            m1 = m2;

            m2 = (temp + m1) % m;

            if (m1 % m == 0 && m2 % m == 1)
            {
                break;
            }
            cnt++;
        }

        cout << i << " " << cnt - 1 << '\n';
    }

    return 0;
}
