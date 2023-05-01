#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    // priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    while (!pq.empty())
    {
        if (pq.size() == 1)
        {
            if (pq.top() < K)
                return -1;
            else
                return answer;
        }

        if (pq.top() < K)
        {
            int tFood = pq.top();
            pq.pop();
            tFood += 2 * pq.top();
            pq.pop();
            pq.push(tFood);
            answer++;
        }
        else
            return answer;
    }
    return -1;
}