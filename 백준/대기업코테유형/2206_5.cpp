#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
int arr[1001][1001];
int visited[1001][1001][2];
queue<pair<int, pair<int, int>>> q;

int bfs(int x, int y)
{
    visited[x][y][1] = 1;
    q.push({1, {x, y}});

    while (!q.empty())
    {
        int curr_x = q.front().second.first;
        int curr_y = q.front().second.second;
        int wallable = q.front().first;

        q.pop();

        if (curr_x == n - 1 && curr_y == m - 1)
        {
            return visited[curr_x][curr_y][wallable];
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }
            else
            {
                if (arr[nx][ny] == 1 && wallable)
                {
                    q.push({0, {nx, ny}});
                    visited[nx][ny][wallable - 1] = visited[curr_x][curr_y][wallable] + 1;
                }
                else if (arr[nx][ny] == 0 && visited[nx][ny][wallable] == 0)
                {
                    q.push({wallable, {nx, ny}});
                    visited[nx][ny][wallable] = visited[curr_x][curr_y][wallable] + 1;
                }
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    string str;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = int(str[j]) - '0';
        }
    }

    cout << bfs(0, 0) << '\n';

    return 0;
}
