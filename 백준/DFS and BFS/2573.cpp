// #TODO: 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다. 이 부분 로직을 제대로 고려하지 않아서
// 오랜 시간 헤맴
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

    int tc = 0;
    int melt = 0;
    int endflag = 0;

    while (1)
    {
        dfsCount = 0;
        melt = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (arr[i][j] > 0 && !visited[i][j])
                {
                    dfs(i, j);
                    dfsCount++;
                }
                else if (arr[i][j] == 0)
                {
                    melt++;
                }
            }
        }
        if (melt == n * m)
        {
            endflag = 1;
            break;
        }

        if (dfsCount >= 2)
        {
            break;
        }
        else
        {
            memset(visited, 0, sizeof(visited));
            memcpy(arr, snow, sizeof(snow));
            // year++;
            tc++;
        }
    }

    if (endflag == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << tc << endl;
    }

    return 0;
}