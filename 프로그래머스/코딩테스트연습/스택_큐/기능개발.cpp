#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++)
    {
        int restProgress = (int)((100 - progresses[i]) / speeds[i]);

        if ((100 - progresses[i]) % speeds[i] != 0)
        {
            restProgress += 1;
        }
        q.push(restProgress);
    }

    int nCount = 1;

    int curr = q.front();
    q.pop();

    while (!q.empty())
    {
        if (curr >= q.front())
        {
            nCount++;
            q.pop();
        }
        else
        {
            answer.push_back(nCount);
            curr = q.front();
            q.pop();
            nCount = 1;
        }
    }
    answer.push_back(nCount);

    return answer;
}