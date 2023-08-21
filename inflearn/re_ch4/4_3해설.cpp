#include <iostream>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int board[102][102], cnt = 0;
void DFS(int x, int y)
{
    board[x][y] = 0;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        if (board[x + dx[i]][y + dy[i]] == 1)
        {
            DFS(x + dx[i], y + dy[i]);
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, m, k, res = INT_MIN;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] == 1)
            {
                cnt = 0;
                DFS(i, j);
                res = max(res, cnt);
            }
        }
    }
    cout << res;
    return 0;
}
