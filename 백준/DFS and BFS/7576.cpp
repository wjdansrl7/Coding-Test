#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[1001][1001];
int arr[1001][1001];
int dist[1001][1001];
int maxDay = 0;
int m, n; // m : 가로, n : 세로
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<pair<int, int>> q;

// 1 : 익은 토마토, 0 : 덜 익은 토마토, -1 : 비어있는 공간
void bfs()
{
    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
                continue;
            else
            {
                if (arr[nx][ny] == -1)
                {
                    continue;
                }
                else
                {
                    if (arr[nx][ny] == 0)
                    {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                        dist[nx][ny] = dist[curr_x][curr_y] + 1;

                        if (maxDay < dist[nx][ny])
                        {
                            maxDay = dist[nx][ny];
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> m >> n;
    int day = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 1)
            {
                q.push({i, j});
                visited[i][j] = true;
                dist[i][j] = 1;
            }
            else if (arr[i][j] == -1)
            {
                dist[i][j] = -1;
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == 0)
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    if (maxDay != 0)
    {
        cout << maxDay - 1 << '\n';
    }
    else
        cout << 0 << '\n';

    return 0;
}
