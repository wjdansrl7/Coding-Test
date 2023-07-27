#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[1001][1001], dis[2][1001][1001];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int w, h;
queue<pair<int, int>> q;

void bfs(int L)
{
    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && dis[L][nx][ny] == 0)
            {
                if (arr[nx][ny] != 1)
                {
                    q.push({nx, ny});
                    dis[L][nx][ny] = dis[L][curr_x][curr_y] + 1;
                }
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

    cin >> w >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> arr[i][j];
        }
    }

    int j;
    for (int i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (arr[i][j] == 2)
            {
                q.push({i, j});
                dis[0][i][j] = 1;
                bfs(0);
                break;
            }
        }
        if (j < w)
        {
            break;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] == 3)
            {
                q.push({i, j});
                dis[1][i][j] = 1;
                bfs(1);
            }
        }
    }

    int min = INT_MAX;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] == 4 && dis[0][i][j] != 0 && dis[1][i][j] != 0)
            {
                int res = dis[0][i][j] + dis[1][i][j];

                if (min > res)
                {
                    min = res;
                }
            }
        }
    }

    cout << min - 2 << '\n';

    return 0;
}
