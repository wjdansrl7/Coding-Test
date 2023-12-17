#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n, m;
int pan[9][9];
int visited[9][9] = {
    0,
};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<pair<int, int>> cctv;

int res = INT_MAX;

void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> pan[i][j];

            if (pan[i][j] != 0 && pan[i][j] != 6)
            {
                cctv.push_back({i, j});
            }
            if (pan[i][j] != 0)
            {
                visited[i][j]++;
            }
        }
    }
}

void move(int x, int y, int dir)
{
    while (true)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
        {
            visited[nx][ny]++;
            x = nx;
            y = ny;
        }
        else
        {
            break;
        }
    }
}

void moveBackTracking(int x, int y, int dir)
{
    while (true)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
        {
            visited[nx][ny]--;
            x = nx;
            y = ny;
        }
        else
        {
            break;
        }
    }
}

void DFS(int L)
{

    if (L == cctv.size())
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j])
                {
                    ans++;
                }
            }
        }

        res = min(res, ans);

        return;
    }

    for (int i = L; i < cctv.size(); i++)
    {
        int x = cctv[i].first;
        int y = cctv[i].second;

        if (pan[x][y] == 1)
        {
            for (int j = 0; j < 4; j++)
            {
                move(x, y, j);
                DFS(L + 1);
                moveBackTracking(x, y, j);
            }
        }
        else if (pan[x][y] == 2)
        {
            // 상하
            move(x, y, 0);
            move(x, y, 1);
            DFS(L + 1);
            moveBackTracking(x, y, 0);
            moveBackTracking(x, y, 1);

            // 좌우
            move(x, y, 2);
            move(x, y, 3);
            DFS(L + 1);
            moveBackTracking(x, y, 2);
            moveBackTracking(x, y, 3);
        }
        else if (pan[x][y] == 3)
        {
            // 상
            move(x, y, 0);
            for (int j = 2; j < 4; j++)
            {
                move(x, y, j);
                DFS(L + 1);
                moveBackTracking(x, y, j);
            }
            moveBackTracking(x, y, 0);

            // 하
            move(x, y, 1);
            for (int j = 2; j < 4; j++)
            {
                move(x, y, j);
                DFS(L + 1);
                moveBackTracking(x, y, j);
            }
            moveBackTracking(x, y, 1);
        }
        else if (pan[x][y] == 4)
        {
            for (int j = 0; j < 4; j++)
            {
                move(x, y, j);
            }
            for (int j = 0; j < 4; j++)
            {
                moveBackTracking(x, y, j);
                DFS(L + 1);
                move(x, y, j);
            }
            for (int j = 0; j < 4; j++)
            {
                moveBackTracking(x, y, j);
            }
        }
        else if (pan[x][y] == 5)
        {
            for (int j = 0; j < 4; j++)
            {
                move(x, y, j);
            }
            DFS(L + 1);
            for (int j = 0; j < 4; j++)
            {
                moveBackTracking(x, y, j);
            }
        }
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
