#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

int n, m, k;
int arr[101][101];
bool visited[101][101];
stack<pair<int, int>> stk;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int dfs(int x, int y)
{
    int cnt = 0;
    visited[x][y] = true;
    stk.push({x, y});
    cnt++;

    while (!stk.empty())
    {
        int xx = stk.top().first;
        int yy = stk.top().second;
        stk.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
            {
                if (arr[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    stk.push({nx, ny});
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    // freopen("in10.txt", "r", stdin);

    cin >> n >> m >> k;

    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        arr[x - 1][y - 1] = 1;
    }

    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                int tmp = dfs(i, j);
                if (res < tmp)
                {
                    res = tmp;
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}
