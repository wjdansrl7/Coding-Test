#include <iostream>
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

void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> pan[i][j];

            // 벽과 빈 공간이 아닐 시 cctv 위치 저장
            if (pan[i][j] != 0 && pan[i][j] != 6)
            {
                cctv.push_back({i, j});
            }
        }
    }
}

void cctv1(int x, int y, int L)
{
    for (int i = 0; i < 4; i++)
    {
        int nx, ny;
        while (true)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
            {
                visited[nx][ny] += 1;
                x = nx;
                y = ny;
            }
            else
            {
                break;
            }
        }
        DFS(L + 1);
        while (!(nx == x && ny == y))
        {

            nx -= dx[i];
            ny -= dy[i];

            visited[nx][ny] -= 1;
        }
    }
}
// 2방향인데 직선 모양
void cctv2(int x, int y, int L)
{
    // 상하
    for (int i = 0; i < 2; i++)
    {
        int nx, ny;
        while (true)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
            {
                visited[nx][ny] += 2;
            }
            else
            {
                break;
            }
        }
    }

    DFS(L + 1);

    // 상하 해제
    for (int i = 0; i < 2; i++)
    {
        int nx, ny;
        while (true)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
            {
                visited[nx][ny] -= 2;
            }
            else
            {
                break;
            }
        }
    }

    // 좌우
    for (int i = 2; i < 4; i++)
    {
        int nx, ny;
        while (true)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
            {
                visited[nx][ny] += 2;
            }
            else
            {
                break;
            }
        }
    }

    DFS(L + 1);

    // 좌우 해제
    for (int i = 2; i < 4; i++)
    {
        int nx, ny;
        while (true)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
            {
                visited[nx][ny] -= 2;
            }
            else
            {
                break;
            }
        }
    }
}
// 2방향인데 대각선이어야 함.
void cctv3(int x, int y, int L)
{
    // 상
    while (true)
    {
        int nx = x + dx[0];
        int ny = y + dy[0];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
        {
            visited[nx][ny] += 3;
            x = nx;
            y = ny;
        }
        else
        {
            break;
        }
    }

    // 좌 우 에 대해
    for (int i = 2; i < 4; i++)
    {
        int nx, ny;
        while (true)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
            {
                visited[nx][ny] += 3;
                x = nx;
                y = ny;
            }
            else
            {
                break;
            }
        }
        DFS(L + 1);

        while (true)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && ny < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
            {
                visited[nx][ny] -= 3;
                x = nx;
                y = ny;
            }
            else
            {
                break;
            }
        }
    }
}
// 3방향
void cctv4(int x, int y, int L)
{
    for (int i = 0; i < 4; i++)
    {
        int nx, ny;
        while (true)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
            {
                visited[nx][ny] += 4;
                x = nx;
                y = ny;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int nx, ny;
        while (true)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
            {
                visited[nx][ny] -= 4;
                x = nx;
                y = ny;
            }
            else
            {
                break;
            }
        }
        DFS(L + 1);

        while (!(nx == x && ny == y))
        {
            nx -= dx[i];
            ny -= dy[i];

            visited[nx][ny] += 4;
        }
    }
}
// 4방향
void cctv5(int x, int y, int L)
{

    for (int i = 0; i < 4; i++)
    {
        int nx, ny;
        while (true)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] != 6)
            {
                visited[nx][ny] += 5;
                x = nx;
                y = ny;
            }
            else
            {
                break;
            }
        }
    }

    DFS(L + 1);
}

void DFS(int L)
{
    if (L == cctv.size())
    {
        return;
    }

    for (int i = L; i < cctv.size(); i++)
    {
        int x = cctv[i].first;
        int y = cctv[i].second;

        if (pan[x][y] == 1)
        {
            cctv1(x, y, i);
        }
        else if (pan[x][y] == 2)
        {
        }
        else if (pan[x][y] == 3)
        {
        }
        else if (pan[x][y] == 4)
        {
        }
        else if (pan[x][y] == 5)
        {
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
