#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int dx[] = {-1, 0, 1, 0}; // 상,우,하,좌
int dy[] = {0, 1, 0, -1};
int n, m; // 세로, 가로
int pan[9][9];
int visited[9][9] = {
    0,
};
vector<pair<int, int>> cctv;
int res = INT_MAX;

void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> pan[i][j];

            if (pan[i][j] != 0)
            {
                visited[i][j] += 1;
                if (pan[i][j] != 6)
                    cctv.push_back({i, j});
            }
        }
}

void move(int x, int y, int dir)
{
    dir %= 4;
    while (true)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
        {
            visited[nx][ny] += 1;
            x = nx;
            y = ny;
        }
        else
            break;
    }
}

void DFS(int L)
{
    if (L == cctv.size())
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (visited[i][j] == 0)
                    ans++;
        res = min(res, ans);

        return;
    }

    int tmp[9][9];
    for (int k = 0; k < 4; k++)
    {

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp[i][j] = visited[i][j];

        int x = cctv[L].first;
        int y = cctv[L].second;

        if (pan[x][y] == 1)
        {
            move(x, y, k);
        }
        else if (pan[x][y] == 2)
        {
            move(x, y, k);
            move(x, y, k + 2);
        }
        else if (pan[x][y] == 3)
        {
            move(x, y, k);
            move(x, y, k + 1);
        }
        else if (pan[x][y] == 4)
        {
            move(x, y, k);
            move(x, y, k + 1);
            move(x, y, k + 2);
        }
        else if (pan[x][y] == 5)
        {
            move(x, y, k);
            move(x, y, k + 1);
            move(x, y, k + 2);
            move(x, y, k + 3);
        }

        DFS(L + 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                visited[i][j] = tmp[i][j];
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    DFS(0);
    cout << res;

    return 0;
}
