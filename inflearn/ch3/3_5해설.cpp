#include <iostream>
#include <queue>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> pan(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> pan[i][j];
        }
    }
    int sx, sy, ex, ey;
    cin >> sx >> sy;
    cin >> ex >> ey;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    pan[sx][sy] = 2;
    while (!q.empty())
    {
        // 매 방향이 결정될 때마다 x, y는 바뀌면 안된다.
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x;
            int yy = y;
            while (xx + dx[i] > 0 && xx + dx[i] <= n && yy + dy[i] > 0 && yy + dy[i] <= n && pan[xx + dx[i]][yy + dy[i]] != 1)
            {
                // 값이 없을 때만 갱신된다.
                if (pan[xx + dx[i]][yy + dy[i]] == 0) // 이미 값이 있으면 갱신하면 안됨(그 값이 더 작은 것이므로)
                {
                    q.push(make_pair(xx + dx[i], yy + dy[i]));
                    pan[xx + dx[i]][yy + dy[i]] = pan[x][y] + 1;
                }
                xx = xx + dx[i];
                yy = yy + dy[i];
            }
        }
    }
    if (pan[ex][ey] == 0)
    {
        cout << "-1";
    }
    else
    {
        cout << pan[ex][ey] - 3;
    }

    return 0;
}
