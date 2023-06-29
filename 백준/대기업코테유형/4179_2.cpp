#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int r, c;
queue<pair<int, pair<int, int>>> q2;
queue<pair<int, pair<int, int>>> q;
int visited[1001][1001];
int visited2[1001][1001];
char arr[1001][1001];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int endflag;
int res = 987654321;

void bfs(int x, int y, int dist)
{
    q.push({dist, {x, y}});
    visited2[x][y] = dist; // 1부터 시작

    while (!q.empty())
    {
        int curr_x = q.front().second.first;
        int curr_y = q.front().second.second;
        int curr_dist = q.front().first;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || nx > r || ny < 1 || ny > c || visited2[nx][ny] != 0 || arr[nx][ny] == '#')
            {
                continue;
            }
            else
            {
                q.push({curr_dist + 1, {nx, ny}});
                visited2[nx][ny] = curr_dist + 1;
                // cout << nx << ny << '\n';
            }
        }
    }
}

void dfs(int x, int y, int dist)
{
    q2.push({dist, {x, y}});
    visited[x][y] = dist;

    while (!q2.empty())
    {
        // int curr_x = q2.top().second.first;
        // int curr_y = q2.top().second.second;
        // int curr_dist = q2.top().first;
        int curr_x = q2.front().second.first;
        int curr_y = q2.front().second.second;
        int curr_dist = q2.front().first;

        q2.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || nx > r || ny < 1 || ny > c || arr[nx][ny] == '#' || visited[nx][ny] != 0)
            {
                continue;
            }
            else
            {
                visited[nx][ny] = curr_dist + 1;
                q2.push({curr_dist + 1, {nx, ny}});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    int Jx, Jy, Fx, Fy;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'J')
            {
                Jx = i;
                Jy = j;
            }
            if (arr[i][j] == 'F')
            {
                Fx = i;
                Fy = j;
            }
            if (arr[i][j] == '#')
            {
                visited2[i][j] = -1;
                visited[i][j] = -1;
            }
        }
    }

    bfs(Fx, Fy, 1);

    dfs(Jx, Jy, 1);

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i == 1 && arr[i][j] != '#')
            {
                if (visited[i][j] < visited2[i][j] || visited2[i][j] == 0)
                {
                    if (res > visited[i][j])
                    {
                        res = visited[i][j];
                    }
                }
            }
            if (i == r && arr[i][j] != '#')
            {
                if (visited[i][j] < visited2[i][j] || visited2[i][j] == 0)
                {
                    if (res > visited[i][j])
                    {
                        res = visited[i][j];
                    }
                }
            }
            if (j == 1 && arr[i][j] != '#')
            {
                if (visited[i][j] < visited2[i][j] || visited2[i][j] == 0)
                {
                    if (res > visited[i][j])
                    {
                        res = visited[i][j];
                    }
                }
            }
            if (j == c && arr[i][j] != '#')
            {
                if (visited[i][j] < visited2[i][j] || visited2[i][j] == 0)
                {
                    if (res > visited[i][j])
                    {
                        res = visited[i][j];
                    }
                }
            }
        }
    }
    if (res == 987654321)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
        cout << res << '\n';

    return 0;
}
