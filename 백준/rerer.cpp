#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool visited[11][11];
int arr[11][11];

stack<pair<int, int>> stk;
int n;
int cnt;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int arr[11][11], int x, int y)
{
    visited[x][y] = true;
    stk.push({x, y});
    cnt++;

    while (!stk.empty())
    {
        int curr_x = stk.top().first;
        int curr_y = stk.top().second;

        stk.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
                continue;
            else
            {
                if (arr[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    stk.push({nx, ny});
                    cnt++;
                }
            }
        }
    }
}
int main()
{

    int area[101] = {
        0,
    };
    cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && arr[i][j] == 1)
            {
                dfs(arr, i, j);
                area[k++] = cnt;
                cnt = 0;
            }
        }
    }

    if (k == 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        sort(area, area + k);
        cout << k << '\n';
        for (int i = 0; i < k; i++)
        {
            cout << area[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}