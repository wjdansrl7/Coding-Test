#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
int arr[1001][1001];

int bfs(int x, int y)
{
    int res = 987654321;

    bool visited[2][1001][1001] = {
        false,
    };
    queue<pair<int, pair<int, pair<int, int>>>> q;

    visited[1][x][y] = true;
    q.push({1, {1, {x, y}}});

    while (!q.empty())
    {
        int curr_dist = q.front().first;
        int wallable = q.front().second.first;
        int curr_x = q.front().second.second.first;
        int curr_y = q.front().second.second.second;

        cout << curr_dist << " " << wallable << " " << curr_x << " " << curr_y << '\n';

        q.pop();

        if (curr_x == n - 1 && curr_y == m - 1)
        {
            if (curr_dist < res)
            {
                res = curr_dist;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[0][nx][ny])
            {
                continue;
            }
            else
            {
                if (arr[nx][ny] == 1)
                {
                    if (wallable == 1)
                    {

                        q.push({curr_dist + 1, {0, {nx, ny}}});
                        visited[0][nx][ny] = true;
                    }
                }
                else
                {
                    q.push({curr_dist + 1, {wallable, {nx, ny}}});
                    visited[wallable][nx][ny] = true;
                }
            }
        }
    }

    return res;

    // 벽을 통과한 경우와(0) 통과하지 않은 경우를(1) 나눈다.
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> str;

        for (int j = 0; j < m; j++)
        {
            arr[i][j] = int(str[j]) - '0';
        }
    }

    int result = bfs(0, 0);

    if (result != 987654321)
        cout << result << '\n';
    else
        cout << -1 << '\n';

    return 0;
}
