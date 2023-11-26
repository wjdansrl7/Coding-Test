#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> pan;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int res = 0;

extern vector<vector<int>> move_up(vector<vector<int>> v);
extern vector<vector<int>> move_down(vector<vector<int>> v);
extern vector<vector<int>> move_right(vector<vector<int>> v);
extern vector<vector<int>> move_left(vector<vector<int>> v);

void dfs(int L, vector<vector<int>> v)
{
    if (L == 5)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res = max(res, v[i][j]);
        return;
    }

    dfs(L + 1, move_up(v));
    dfs(L + 1, move_down(v));
    dfs(L + 1, move_right(v));
    dfs(L + 1, move_left(v));
}

vector<vector<int>> move_up(vector<vector<int>> v) // 0
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 0)
                continue;

            int x = i;
            int y = j;
            while (1)
            {
                int nx = x + dx[0];
                int ny = y + dy[0];

                // 경계값을 넘는 경우
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
                    break;

                // 값이 들어있는 경우
                if (v[nx][ny] != 0)
                {
                    // 이동할 값과 현재 값이 같은 경우
                    if (v[nx][ny] == v[x][y])
                    {
                        v[nx][ny] *= 2;
                        v[x][y] = 0;
                        visited[nx][ny] = true;
                    }
                    break;
                }
                // 이동할 칸이 빈 값인 경우
                else
                {
                    v[nx][ny] = v[x][y];
                    v[x][y] = 0;
                    x = nx;
                    y = ny;
                }
            }
        }
    }

    return v;
}

vector<vector<int>> move_down(vector<vector<int>> v) // 1
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 0)
                continue;

            int x = i;
            int y = j;
            while (1)
            {

                int nx = x + dx[1];
                int ny = y + dy[1];

                // 경계값을 넘는 경우
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
                    break;

                if (v[nx][ny] != 0)
                {
                    if (v[nx][ny] == v[x][y])
                    {
                        v[nx][ny] *= 2;
                        v[x][y] = 0;
                        visited[nx][ny] = true;
                    }
                    break;
                }
                else
                {
                    // 이동할 칸이 빈 값인 경우
                    v[nx][ny] = v[x][y];
                    v[x][y] = 0;
                    x = nx;
                    y = ny;
                }
            }
        }
    }

    return v;
}

vector<vector<int>> move_right(vector<vector<int>> v) // 3
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i][j] == 0)
                continue;

            int x = i;
            int y = j;
            while (1)
            {
                int nx = x + dx[3];
                int ny = y + dy[3];

                // 경계값을 넘는 경우
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
                    break;

                if (v[nx][ny] != 0)
                {
                    if (v[nx][ny] == v[x][y])
                    {
                        v[nx][ny] *= 2;
                        v[x][y] = 0;
                        visited[nx][ny] = true;
                    }
                    break;
                }
                // 이동할 칸이 빈 값인 경우
                else
                {
                    v[nx][ny] = v[x][y];
                    v[x][y] = 0;
                    x = nx;
                    y = ny;
                }
            }
        }
    }

    return v;
}

vector<vector<int>> move_left(vector<vector<int>> v)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i][j] == 0)
                continue;

            int x = i;
            int y = j;
            while (1)
            {
                int nx = x + dx[2];
                int ny = y + dy[2];

                // 경계값을 넘는 경우
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
                    break;

                if (v[nx][ny] != 0)
                {
                    if (v[nx][ny] == v[x][y])
                    {
                        v[nx][ny] *= 2;
                        v[x][y] = 0;
                        visited[nx][ny] = true;
                    }
                    break;
                }
                // 이동할 칸이 빈 값인 경우
                else
                {
                    v[nx][ny] = v[x][y];
                    v[x][y] = 0;
                    x = nx;
                    y = ny;
                }
            }
        }
    }
    return v;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    pan.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> pan[i][j];

    dfs(0, pan);

    cout << res;

    return 0;
}
