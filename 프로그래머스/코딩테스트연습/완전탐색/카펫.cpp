#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int temp;
    int nCount = 0;

    for (int i = 1; i <= yellow; i++)
    {
        if ((brown - 4) % 2 == 0 && yellow % i == 0)
        {
            if ((brown - 4) / 2 == i + yellow / i)
            {
                temp = i + 2;
                answer.push_back(temp);
                nCount++;
            }
        }
    }

    if (nCount == 1)
        answer.push_back(temp);

    sort(answer.begin(), answer.end(), greater<>());
    return answer;
}