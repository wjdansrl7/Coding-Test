#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF (987654321)
using namespace std;

int n;
int arr[126][126];
int dist[126][126];
queue<pair<int, int>> q;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int dfs()
{
    dist[0][0] = arr[0][0];
    q.push({0, 0});

    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            {
                continue;
            }
            else
            {
                if (dist[nx][ny] > dist[curr_x][curr_y] + arr[nx][ny])
                {
                    dist[nx][ny] = dist[curr_x][curr_y] + arr[nx][ny];
                    q.push({nx, ny});
                }
            }
        }
    }

    return dist[n - 1][n - 1];
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;

    while (1)
    {
        memset(dist, 0, sizeof(dist));
        memset(arr, 0, sizeof(arr));
        cin >> n;

        if (n == 0)
        {
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                dist[i][j] = INF;
            }
        }

        cout << "Problem " << tc++ << ": " << dfs() << '\n';
    }

    return 0;
}
