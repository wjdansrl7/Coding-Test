#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int r, c; // r: 행, c: 열
char arr[1001][1001];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

stack<pair<int, pair<int, int>>> stk;
queue<pair<int, int>> stk2;
bool visited[1001][1001];

int res = 987654321;

void dfs(int x, int y, int dist, int Fx, int Fy)
{
    stk2.push({Fx, Fy});
    stk.push({dist, {x, y}});

    visited[Fx][Fy] = true; // 불
    visited[x][y] = true;   // 지훈

    while (!stk.empty())
    {
        int curr_Fx = stk2.front().first;
        int curr_Fy = stk2.front().second;

        stk2.pop();

        // 불의 이동
        for (int i = 0; i < 4; i++)
        {
            int nx = curr_Fx + dx[i];
            int ny = curr_Fy + dy[i];

            if (nx < 1 || nx > r || ny < 1 || ny > c || arr[nx][ny] == '#')
            {
                continue;
            }
            else
            {
                visited[nx][ny] = true;
                stk2.push({nx, ny});
            }
        }

        // 지훈이의 이동
        int curr_x = stk.top().second.first;
        int curr_y = stk.top().second.second;
        int curr_dist = stk.top().first;

        if (curr_x == 1 || curr_x == r)
        {
            if (res > curr_dist)
            {
                res = curr_dist;
            }
        }
        if (curr_y == 1 || curr_y == r)
        {
            if (res > curr_dist)
            {
                res = curr_dist;
            }
        }

        stk.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || nx > r || ny < 1 || ny > c || visited[nx][ny] || arr[nx][ny] == '#')
            {
                continue;
            }
            else
            {
                visited[nx][ny] = true;
                stk.push({curr_dist + 1, {nx, ny}});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    int start_x, start_y;
    int start_Fx, start_Fy;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'J')
            {
                start_x = i;
                start_y = j;
            }
            if (arr[i][j] == 'F')
            {
                start_Fx = i;
                start_Fy = j;
            }
        }
    }

    dfs(start_x, start_y, 0, start_Fx, start_Fy);

    if (res == 987654321)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
        cout << res + 1 << '\n';

    return 0;
}
