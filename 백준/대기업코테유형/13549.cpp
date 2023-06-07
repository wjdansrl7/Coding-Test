#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int visited[100001] = {
    0,
};
int minTime;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void bfs()
{
    pq.push({0, n});

    visited[pq.top().second] = 1;

    while (!pq.empty())
    {
        int curr_num = pq.top().second;
        int curr_time = pq.top().first;

        pq.pop();

        if (curr_num == k)
        {
            minTime = visited[curr_num] - 1;
            return;
        }

        if (curr_num * 2 <= 100000 && !visited[curr_num * 2])
        {
            visited[curr_num * 2] = visited[curr_num];
            pq.push({curr_time, curr_num * 2});
        }
        if (curr_num + 1 <= 100000 && !visited[curr_num + 1])
        {
            visited[curr_num + 1] = visited[curr_num] + 1;
            pq.push({curr_time + 1, curr_num + 1});
        }
        if (curr_num - 1 >= 0 && !visited[curr_num - 1])
        {
            visited[curr_num - 1] = visited[curr_num] + 1;
            pq.push({curr_time + 1, curr_num - 1});
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    bfs();

    cout << minTime << '\n';

    return 0;
}
