#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m; // n : 세로, m : 가로
int maxResult = 0;

bool visited[501][501] = {
    false,
};
int arr[501][501];
stack<pair<int, int>> stk;

void dfs(int x, int y)
{
    int cnt = 0;
    visited[x][y] = true;
    stk.push({x, y});
    cnt++;

    while (!stk.empty())
    {
        int curr_x = stk.top().first;
        int curr_y = stk.top().second;

        stk.pop();

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
                if (arr[nx][ny] == 1)
                {
                    cnt++;
                    stk.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    if (maxResult < cnt)
    {
        maxResult = cnt;
    }
}
int main(int argc, char const *argv[])
{
    int cnt = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && arr[i][j] == 1)
            {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    cout << maxResult << '\n';

    return 0;
}
