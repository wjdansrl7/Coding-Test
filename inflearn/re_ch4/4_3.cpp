#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

int n, m, k;
int arr[101][101];
bool visited[101][101];
int res = INT_MIN;
stack<pair<int, int>> stk;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void DFS(int x, int y)
{
    int cnt = 0;
    stk.push({x, y});
    visited[x][y] = true;
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

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || arr[nx][ny] == 0)
            {
                continue;
            }
            else
            {
                stk.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    res = max(res, cnt);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in10.txt", "r", stdin);

    cin >> n >> m >> k;

    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        arr[x - 1][y - 1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                DFS(i, j);
            }
        }
    }

    cout << res;

    return 0;
}
