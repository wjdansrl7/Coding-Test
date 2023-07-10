#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;

int minRes;

void bfs(int start, vector<pair<int, int>> p[401])
{
    for (int i = 0; i < p[start].size(); i++)
    {
        queue<pair<int, int>> q;
        bool visited[401] = {
            false,
        };
        visited[start] = true;
        if (minRes > p[start][i].second)
        {
            q.push({p[start][i].first, p[start][i].second});
        }

        while (!q.empty())
        {
            int next_node = q.front().first;  // 2
            int curr_cost = q.front().second; // 1
            q.pop();

            if (!visited[next_node])
            {
                for (int i = 0; i < p[next_node].size(); i++)
                {
                    if (minRes > p[next_node][i].second + curr_cost)
                    {
                        q.push({p[next_node][i].first, p[next_node][i].second + curr_cost});
                    }
                }
                visited[next_node] = true;
            }

            if (next_node == start)
            {
                if (minRes > curr_cost)
                {
                    minRes = curr_cost;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        minRes = 987654321;
        vector<pair<int, int>> p[401];

        cin >> n >> m;

        int x, y, c;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> c;
            p[x].push_back({y, c});
        }

        for (int start = 1; start <= n; start++)
        {
            bfs(start, p);
        }

        if (minRes == 987654321)
        {
            cout << "#" << tc << " " << -1 << '\n';
        }
        else
        {
            cout << "#" << tc << " " << minRes << '\n';
        }
    }

    return 0;
}
