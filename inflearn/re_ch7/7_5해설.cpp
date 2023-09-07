#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;

struct Loc
{
    int x, y, z;
    Loc(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
};

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int board[101][101], dist[101][101][3];
int n;
queue<Loc> Q;

void BFS()
{
    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        int z = Q.front().z;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n)
                continue;
            if (board[nx][ny] == 0 && dist[nx][ny][z] == -1)
            {
                Q.push(Loc(nx, ny, z));
                dist[nx][ny][z] = dist[x][y][z] + 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    memset(dist, -1, sizeof(dist));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int x, y;
        cin >> x >> y;
        Q.push(Loc(x, y, i));
        dist[x][y][i] = 0;
    }
    BFS();

    int dis = INT_MAX, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x = dist[i][j][0];
            int y = dist[i][j][1];
            int z = dist[i][j][2];
            int k = max(max(x, y), z);
            if (min(min(x, y), z) != -1)
            {
                if (k < dis)
                {
                    dis = k;
                    cnt = 1;
                }
                else if (k == dis)
                {
                    cnt++;
                }
            }
        }
    }
    if (cnt == 0)
    {
        cout << -1;
    }
    else
        cout << cnt;

    return 0;
}
