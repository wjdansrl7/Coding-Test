#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int n;
int arr[101][101];
int pan[3][101][101];
bool visited[3][101][101];

void BFS(int x, int y, int idx)
{
    queue<pair<int, int>> q;
    visited[idx][x][y] = true;
    q.push({x, y});

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] != 1 && !visited[idx][nx][ny])
            {
                visited[idx][nx][ny] = true;
                pan[idx][nx][ny] = pan[idx][xx][yy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int x, y;
    for (int i = 0; i < 3; i++)
    {
        cin >> x >> y;
        BFS(x - 1, y - 1, i);
    }

    int res[101][101];
    int minRes = INT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (pan[0][i][j] != 0 && pan[1][i][j] != 0 && pan[2][i][j] != 0)
            {
                res[i][j] = max(pan[0][i][j], max(pan[1][i][j], pan[2][i][j]));
                minRes = min(minRes, res[i][j]);
            }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (res[i][j] == minRes)
                cnt++;
    if (cnt == 0)
        cout << -1;
    else
        cout << cnt;

    return 0;
}
