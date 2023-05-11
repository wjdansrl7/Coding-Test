/*
참고한 풀이...
먼저 N이 1개인 경우는 당연히 경우의 수가 N뿐입니다.
N이 2개인 경우는 NN과 N+N, N-N, N*N, N/N이 가능합니다.
N이 3개인 경우는 NNN과 (NN+N, NN-N, NN*N, NN/N), ((N+N)+N), (N+N)-N, (N+N)*N. (N+N)/N), ((N-N)+N), (N-N)-N, (N-N)*N. (N-N)/N), ((N*N)+N), (N*N)-N, (N*N)*N. (N*N)/N), ((N/N)+N), (N/N)-N, (N/N)*N. (N/N)/N)이 가능합니다.
이것은 다르게 말하면 s[2]는 NNN과 s[1]과 s[0]의 사칙연산, s[0]과 s[1]의 사칙연산의 합이라고 말할 수 있습니다.



*/

#include <string>
#include <unordered_set>

using namespace std;

int solution(int N, int number)
{
    int answer = -1;         // 최솟값이 8보다 크면 -1을 return
    unordered_set<int> s[8]; // 정렬할 필요X, 중복제거는 필요 - unordered_set 사용

    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        sum = 10 * sum + N;
        s[i].insert(sum);
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
                    {
                        s[i].insert(a / b);
                    }
                }
            }
        }
    }

    // set을 채웠으니 Number가 set에 들어가 있는지 여부만 확인하면 된다.
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