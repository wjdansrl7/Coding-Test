#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#define INF (987654321)
using namespace std;

int n, m;
deque<pair<int, int>> q[50001];
queue<pair<int, int>> v;
int dist[50001];
bool visited[50001];

void dijkstra()
{
    v.push({0, 1});

    while (!v.empty())
    {
        int curr_dist = v.front().first;
        int curr_x = v.front().second;

        v.pop();

        for (auto var : q[curr_x])
        {
            if (dist[var.second] > dist[curr_x] + var.first)
            {
                dist[var.second] = dist[curr_x] + var.first;
                v.push({var.first, var.second});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }

    int x, y, z;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        q[x].push_back({z, y});
        q[y].push_back({z, x});
    }

    dist[1] = 0;
    visited[1] = true;

    for (int i = 1; i <= n; i++)
    {
        sort(q[i].begin(), q[i].end());
    }

    dijkstra();

    cout << dist[n] << '\n';

    return 0;
}
