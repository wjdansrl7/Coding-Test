#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;
    int maxClear;
    int temp_k;
    vector<int> ordering;

    for (int i = 0; i < dungeons.size(); i++)
    {
        ordering.push_back(i);
    }

    do
    {
        maxClear = 0;
        temp_k = k;
        for (int i = 0; i < ordering.size(); i++)
        {
            if (temp_k <= 0)
                break;

            if (temp_k >= dungeons[ordering[i]][0])
            {
                temp_k -= dungeons[ordering[i]][1];
                maxClear++;
            }
            else
            {
                continue;
            }
        }

        if (maxClear == dungeons.size())
        {
            answer = maxClear;
            break;
        }
        else
        {
            if (answer < maxClear)
                answer = maxClear;
        }
    } while (next_permutation(ordering.begin(), ordering.end()));

    return answer;
}