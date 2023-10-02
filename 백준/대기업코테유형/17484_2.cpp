#include <iostream>
using namespace std;

const int INF = 2147000000;
const int dx[3] = {-1, 0, 1};
int n, m, ans = INF, board[7][7];

int solve(int y, int x, int last)
{
    if (y == n)
        return 0;

    int ret = INF;
    for (int i = 0; i < 3; i++)
    {
        if (last == i)
        {
            continue;
        }
        if (x + dx[i] < 0 || x + dx[i] >= m)
        {
            continue;
        }
        ret = min(ret, solve(y + 1, x + dx[i], i) + board[y][x]);
    }
    return ret;
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
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        ans = min(ans, solve(0, i, -1));
    }
    cout << ans << '\n';

    return 0;
}
