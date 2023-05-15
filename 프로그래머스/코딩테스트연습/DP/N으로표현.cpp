/*
DP문제이다. 하나의 숫자를 가지고 사칙연산만을 이용해 number를 구하는데
필요한 최소한의 N의 개수를 구하는 문제이다.
나는 처음 문제 접근을 할 때 예시에서 N/N을 하면 값이 1이 나오므로 가장 최악의 경우를 N/N으로
추가하는 것으로 두고 greedy한 방식으로 접근하려고 하였다.
하지만 그렇게 코드를 짰으나 문제를 해결하지 못하였다.
따라서 다른 참고코드를 사용하였다.

참고URL : https://mind-devlog.tistory.com/2

*/

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number)
{
    int answer = -1;
    unordered_set<int> s[8];
    int temp = 0;

    for (int i = 0; i < 8; i++)
    {
        temp = 10 * temp + N;
        s[i].insert(temp);
    }

    for (int i = 1; i < 8; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int a : s[j])
            {
                for (int b : s[i - j - 1])
                {
                    s[i].insert(a + b);
                    s[i].insert(a - b);
                    s[i].insert(a * b);
                    if (b != 0)
                        s[i].insert(a / b);
                }
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if (s[i].find(number) != s[i].end())
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}