#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[8][8];
vector<pair<int, int>> cctv;
int ans = 987654321;

int dx[] = {0, -1, 0, 1}; // 우,상,좌,하
int dy[] = {1, 0, -1, 0};

void check(int x, int y, int dir)
{
    dir %= 4;
    while (1)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            return;
        if (arr[nx][ny] == 6)
            return;
        if (arr[nx][ny] != 0)
            continue;
        arr[nx][ny] = -1;
    }
}

void dfs(int idx)
{
    if (idx == cctv.size())
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!arr[i][j])
                    cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }

    int x = cctv[idx].first;
    int y = cctv[idx].second;
    int tmp[9][9];

    for (int dir = 0; dir < 4; dir++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp[i][j] = arr[i][j];
            }
        }

        if (arr[x][y] == 1)
        {
            check(x, y, dir);
        }
        else if (arr[x][y] == 2)
        {
            check(x, y, dir);
            check(x, y, dir + 2);
        }
        else if (arr[x][y] == 3)
        {
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (arr[x][y] == 4)
        {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
        }
        else if (arr[x][y] == 5)
        {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        dfs(idx + 1);
        // case 종료이므로 초기화
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = tmp[i][j];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0 && arr[i][j] != 6)
            {
                cctv.push_back({i, j});
            }
        }
    }

    dfs(0);
    cout << ans << '\n';

    return 0;
}
