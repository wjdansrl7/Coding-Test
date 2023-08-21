#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int w, h;
int st_x, st_y, et_x, et_y;
vector<pair<int, int>> v;
int arr[1001][1001];
int dist[2][1001][1001];
queue<pair<int, int>> q;

void bfs(int x, int y, int idx)
{
    dist[idx][x][y] = 0;
    q.push({x, y});

    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        int curr_dist = dist[idx][curr_x][curr_y];

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w || arr[nx][ny] == 1 || arr[nx][ny] == 3)
            {
                continue;
            }
            else
            {
                if (dist[idx][nx][ny] == 0)
                {
                    dist[idx][nx][ny] = curr_dist + 1;
                    q.push({nx, ny});
                }
                else
                {
                    if (dist[idx][nx][ny] > curr_dist + 1)
                    {
                        dist[idx][nx][ny] = curr_dist + 1;
                        q.push({nx, ny});
                    }
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

    cin >> w >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 2)
            {
                st_x = i;
                st_y = j;
            }
            if (arr[i][j] == 3)
            {
                et_x = i;
                et_y = j;
            }
            if (arr[i][j] == 4)
            {
                v.push_back({i, j});
            }
        }
    }

    bfs(st_x, st_y, 0);
    bfs(et_x, et_y, 1);

    vector<int> res;
    int ans = INT_MAX;

    for (auto u : v)
    {
        if (dist[0][u.first][u.second] == 0 || dist[1][u.first][u.second] == 0)
        {
            continue;
        }
        ans = min(ans, dist[0][u.first][u.second] + dist[1][u.first][u.second]);
    }

    cout << ans << '\n';

    return 0;
}
