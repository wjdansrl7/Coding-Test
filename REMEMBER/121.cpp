#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < jobs.size(); i++)
    {
        cout << jobs[i][1] << "\n";
    }

    for (auto i : jobs)
    {
        // cout << i[1] << "\n";
        pq.push({i[0], i[1]});
    }

    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }

    return 0;
}
