/*
스택, 큐 -> 다리를 지나는 트럭
문제에서 총 트럭을 지나가는데 걸리는 시간을 어떻게 구해야할지 몰라서
문제를 풀지 못하였다.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int idx = 0;
    int sum = 0;
    queue<int> q;

    while (1)
    {
        if (truck_weights.size() == idx)
        {
            answer += bridge_length;
            break;
        }

        answer++;

        if (q.size() == bridge_length)
        {
            sum -= q.front();
            q.pop();
        }
        if (sum + truck_weights[idx] <= weight)
        {
            sum += truck_weights[idx];
            q.push(truck_weights[idx]);
            idx++;
        }
        else
        {
            q.push(0);
        }
    }

    return answer;
}