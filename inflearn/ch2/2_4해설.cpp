/*
visited 체크 외에 dist로도 check 역할을 할 수 있다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int board[1001][1001], dis[2][1001][1001];
queue<pair<int, int>> Q;
int w, h;

void BFS(int idx)
{
    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && dis[idx][nx][ny] == 0)
            {
                if (board[nx][ny] != 1)
                {
                    dis[idx][nx][ny] = dis[idx][x][y] + 1;
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> board[i][j];
        }
    }

    int j;
    for (int i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (board[i][j] == 2)
            {
                dis[0][i][j] = 1;
                Q.push(make_pair(i, j));
                BFS(0);
                break;
            }
        }
        if (j < w)
        {
            break;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (board[i][j] == 3)
            {
                dis[0][i][j] = 1;
                Q.push(make_pair(i, j));
                BFS(1);
                break;
            }
        }
        if (j < w)
        {
            break;
        }
    }

    int min = 2147000000;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (board[i][j] == 4 && dis[0][i][j] > 0 && dis[1][i][j] > 0)
            {
                int res = dis[0][i][j] + dis[1][i][j];
                if (res < min)
                    min = res;
            }
        }
    }
    cout << min - 2;

    return 0;
}
