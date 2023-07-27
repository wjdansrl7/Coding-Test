#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int n;
int arr[31][31];
int dist[31][31];
queue<pair<int, int>> q;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y)
{
    q.push({x, y});
    dist[x][y] = 2;

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] != 1)
            {
                if (dist[nx][ny] == 0)
                {
                    dist[nx][ny] = dist[xx][yy] + 1;
                    q.push({nx, ny});
                }
                else if (dist[nx][ny] > dist[xx][yy] + 1)
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
    // freopen("in1.txt", "r", stdin);

    int res = INT_MIN;
    cin >> n;

    vector<pair<int, int>> grass;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 2)
            {
                grass.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < grass.size(); i++)
    {
        bfs(grass[i].first, grass[i].second);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (res < dist[i][j])
            {
                res = dist[i][j];
            }
        }
    }

    cout << res - 2 << '\n';

    return 0;
}
