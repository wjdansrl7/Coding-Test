#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define INF 987654321
using namespace std;

int n;
int arr[126][126];
int dist[126][126];
int cnt = 0;
stack<pair<int, pair<int, int>>> stk;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs()
{
    stk.push({arr[0][0], {0, 0}});

    while (!stk.empty())
    {
        int curr_x = stk.top().second.first;
        int curr_y = stk.top().second.second;
        int curr_sum = stk.top().first;

        stk.pop();
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
                if (curr_sum + arr[nx][ny] > dist[nx][ny])
                {
                    continue;
                }

                if (dist[nx][ny] > dist[curr_x][curr_y] + arr[nx][ny])
                {
                    dist[nx][ny] = dist[curr_x][curr_y] + arr[nx][ny];
                    stk.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
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

        dist[0][0] = arr[0][0];

        dfs();

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << '\n';
        // }

        cout << "Problem " << tc++ << ": " << dist[n - 1][n - 1] << '\n';
    }

    return 0;
}
