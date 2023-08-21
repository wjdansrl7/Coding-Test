#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n;
int arr[31][31];
int dist[31][31];
queue<pair<int, int>> q;
int res = INT_MIN;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void BFS(int x, int y)
{
    dist[x][y] = 2;
    q.push({x, y});

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] == 1)
            {
                continue;
            }
            else
            {
                if (dist[nx][ny] == 0)
                {
                    dist[nx][ny] = dist[xx][yy] + 1;
                    q.push({nx, ny});
                }
                if (dist[nx][ny] > dist[xx][yy] + 1)
                {
                    dist[nx][ny] = dist[xx][yy] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 2)
            {
                v.push_back({i, j});
            }
        }
    }

    for (auto x : v)
    {
        BFS(x.first, x.second);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res = max(res, dist[i][j]);
        }
    }

    cout << res - 2;

    return 0;
}
