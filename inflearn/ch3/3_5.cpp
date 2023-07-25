#include <iostream>
#include <queue>
using namespace std;

int n;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int res;

int arr[101][101];
queue<pair<int, int>> q;

void bfs(int st_x, int st_y, int et_x, int et_y)
{
    arr[st_x][st_y] = 2;

    q.push({st_x, st_y});

    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x;
            int ny = curr_y;

            while (nx + dx[i] > 0 && nx + dx[i] <= n && ny + dy[i] > 0 && ny + dy[i] <= n && arr[nx][ny] != 1)
            {
                if (arr[nx + dx[i]][ny + dy[i]] == 0)
                {
                    q.push({nx + dx[i], ny + dy[i]});
                    arr[nx + dx[i]][ny + dy[i]] = arr[curr_x][curr_y] + 1;
                }
                nx = nx + dx[i];
                ny = ny + dy[i];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in5.txt", "r", stdin);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int st_x, st_y, et_x, et_y;

    cin >> st_x >> st_y;
    cin >> et_x >> et_y;

    bfs(st_x, st_y, et_x, et_y);

    if (arr[et_x][et_y] == 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << arr[et_x][et_y] - 3 << '\n';
    }

    return 0;
}
