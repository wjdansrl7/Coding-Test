#include <iostream>
#include <cstring>
#include <stack>
#include <utility>

#define MAXN 301

using namespace std;

int n, m;

int arr[MAXN][MAXN];
bool visited[MAXN][MAXN];
int snow[MAXN][MAXN];

stack<pair<int, int>> stk;
int dfsCount;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int x, int y)
{
    visited[x][y] = true;
    stk.push({x, y});

    while (!stk.empty())
    {
        int curr_x = stk.top().first;
        int curr_y = stk.top().second;

        stk.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > m || visited[nx][ny])
            {
                continue;
            }
            else
            {
                if (arr[nx][ny] > 0)
                {
                    stk.push({nx, ny});
                    visited[nx][ny] = true;
                }
                else if (arr[nx][ny] == 0)
                {
                    snow[curr_x][curr_y] -= 1;
                    if (snow[curr_x][curr_y] < 0)
                    {
                        snow[curr_x][curr_y] = 0;
                    }
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

    memset(arr, 0, sizeof(arr));
    memset(visited, 0, sizeof(visited));
    memset(snow, 0, sizeof(snow));

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    memcpy(snow, arr, sizeof(arr));

    int year = 0;
    int tc = 0;

    while (1)
    {
        dfsCount = 0;
        if (tc > 10)
        {
            break;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (arr[i][j] > 0 && !visited[i][j])
                {
                    dfs(i, j);
                    dfsCount++;
                }
            }
        }
        tc++;

        // TODO: 지울 부분
        // cout << tc << endl;
        // cout << "=============================" << endl;
        // for (int i = 1; i <= n; i++)
        // {
        // for (int j = 1; j <= m; j++)
        // {
        // cout << snow[i][j] << " ";
        // }
        // cout << endl;
        // }

        if (dfsCount >= 2)
        {
            break;
        }
        else
        {
            memset(visited, 0, sizeof(visited));
            memcpy(arr, snow, sizeof(snow));
            // year++;
        }
    }

    // cout << dfsCount << endl;

    if (tc > 10)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << tc - 1 << endl;
    }

    return 0;
}