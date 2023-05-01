#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> result(n, 1);

    for (int i = 0; i < lost.size(); i++)
    {
        result[lost[i] - 1]--;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        result[reserve[i] - 1]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (result[i] == 2)
        {
            if (i - 1 >= 0 && result[i - 1] == 0)
            {
                result[i]--;
                result[i - 1]++;
                continue;
            }
            if (i + 1 < n && result[i + 1] == 0)
            {
                result[i]--;
                result[i + 1]++;
                continue;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (result[i] == 1 || result[i] == 2)
            answer++;
    }

    return answer;
}