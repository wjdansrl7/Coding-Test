#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

int n, m;
int dx[] = {1, 1, 1};
int dy[] = {-1, 0, 1};
int pan[7][7];
int cost[7][7][7];
stack<pair<int, pair<int, int>>> stk;

void DFS(int x, int y, int d)
{
    stk.push({d, {x, y}});
    // cost[y][x][y] = pan[x][y];

    while (!stk.empty())
    {
        int xx = stk.top().second.first;
        int yy = stk.top().second.second;
        int dd = stk.top().first;

        stk.pop();

        for (int i = 0; i < 3; i++)
        {
            // 방향이 같은 경우 X
            if (dd == i)
            {
                continue;
            }

            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                continue;
            }
            else
            {
                if (cost[y][nx][ny] == 0)
                {
                    cost[y][nx][ny] = cost[y][xx][yy] + pan[nx][ny];
                    stk.push({i, {nx, ny}});
                }
                else if (cost[y][nx][ny] != 0 && cost[y][nx][ny] > cost[y][xx][yy] + pan[nx][ny])
                {
                    cost[y][nx][ny] = cost[y][xx][yy] + pan[nx][ny];
                    stk.push({i, {nx, ny}});
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> pan[i][j];
        }
    }

    int res = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        cost[i][0][i] = pan[0][i];
        DFS(0, i, -1);
        for (int j = 0; j < m; j++)
        {
            if (cost[i][n - 1][j] != 0)
            {
                res = min(res, cost[i][n - 1][j]);
            }
        }
    }
    cout << res;

    return 0;
}
