/*
처음에 문제를 제대로 읽지 않아서 한 번 틀렸다.
과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번
이하 인용되었다면 h의 최댓값이 이 과학자의 H-index이다.
이 부분에서 조건식은
i를 최소 인용 횟수라고 한다면, j는 n개의 논문을 iterate
if(citations[j] >= i)
    h++;

나머지 논문은 (n-h)인데 h번 이하이므로, n-h <= h
if(i >= h && n <= 2 * h) 성립해야함을 알 수 있다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    int n = citations.size();
    int h = 0;

    for (int i = 0; i <= 10000; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (citations[j] >= i)
                h++;
        }
        if (i >= h && n <= 2 * h)
            break;
        else
            h = 0;
    }

    answer = h;

    return answer;
}