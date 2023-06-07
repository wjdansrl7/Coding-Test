#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int arr[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<pair<int, int>> q;

void bfs(int x, int y, int distance)
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
            {
                continue;
            }
            else
            {
                dist[nx][ny] = dist[curr_x][curr_y] + 1;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            dist[i][j] = -1;

            if (arr[i][j] == 0)
            {
                visited[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 2)
            {
                visited[i][j] = true;
                dist[i][j] = 0;
                q.push({i, j});
                bfs(i, j, 0);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
