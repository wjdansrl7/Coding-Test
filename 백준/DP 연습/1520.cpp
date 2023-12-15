#include <iostream>
#include <queue>
using namespace std;

int m, n;
int pan[501][501];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int res = 0;
void BFS(int x, int y)
{
    queue<pair<int, pair<int, int>>> q;

    q.push({pan[x][y], {x, y}});

    while (!q.empty())
    {
        int xx = q.front().second.first;
        int yy = q.front().second.second;
        int vv = q.front().first;
        q.pop();

        if (xx == m - 1 && yy == n - 1)
        {
            res++;
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (pan[nx][ny] < vv)
            {
                q.push({pan[nx][ny], {nx, ny}});
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> pan[i][j];

    BFS(0, 0);

    cout << res;

    return 0;
}
