#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
queue<pair<int, int>> q;
int arr[101][101];
int dist[3][101][101];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y, int idx) 
{
    dist[idx][x][y] = 2;
    q.push({x, y});

    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] != 1)
            {
                if (dist[idx][nx][ny] == 0)
                {
                    dist[idx][nx][ny] = dist[idx][curr_x][curr_y] + 1;
                    q.push({nx, ny});
                }
                else if (dist[idx][nx][ny] > dist[idx][curr_x][curr_y] + 1)
                {
                    dist[idx][nx][ny] = dist[idx][curr_x][curr_y] + 1;
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
    cout.tie(NULL);
    freopen("in5.txt", "r", stdin);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 1)
            {
                dist[0][i][j] = 1;
                dist[1][i][j] = 1;
                dist[2][i][j] = 1;
            }
        }
    }

    int x, y;
    for (int i = 0; i < 3; i++)
    {
        cin >> x >> y;
        bfs(x - 1, y - 1, i);
    }

    int res = INT_MAX;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[0][i][j] == 1 || dist[0][i][j] == 0 || dist[1][i][j] == 0 || dist[2][i][j] == 0)
            {
                continue;
            }

            int tmp = max(dist[0][i][j], max(dist[1][i][j], dist[2][i][j]));
            if (res > tmp)
            {
                res = tmp;
                cnt = 1;
                continue;
            }
            else if (res == tmp)
            {
                cnt++;
            }
        }
    }

    if (res == INT_MAX)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << cnt << '\n';
    }

    return 0;
}
