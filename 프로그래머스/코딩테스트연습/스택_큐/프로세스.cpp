#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int, int>> q;
    vector<int> loc;
    vector<int> rank = priorities;

    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({priorities[i], i});
    }

    sort(rank.begin(), rank.end(), greater<>());

    for (int i = 0; i < rank.size(); i++)
    {
        while (!q.empty())
        {
            if (rank[i] != q.front().first)
            {
                int curr_p = q.front().first;
                int curr_in = q.front().second;
                q.pop();
                q.push({curr_p, curr_in});
            }
            else
            {
                loc.push_back(q.front().second);
                q.pop();
                break;
            }
        }
    }

    for (int i = 0; i < loc.size(); i++)
    {
        if (loc[i] == location)
        {
            answer = i + 1;
        }
    }

    return answer;
}