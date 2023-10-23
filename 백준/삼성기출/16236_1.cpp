#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int arr[21][21];
int dist[21][21] = {
    0,
};
int n;
int st_x, st_y, s = 2;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
queue<pair<int, int>> q;
int res = 0, cnt = 0;

void BFS(int x, int y)
{
    int minRes = 1000;
    int m_x, m_y;

    q.push({x, y});

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;

        if (arr[xx][yy] != 0 && arr[xx][yy] < s)
        {
            if (minRes > dist[xx][yy])
            {
                minRes = dist[xx][yy];
                m_x = xx;
                m_y = yy;
            }
            else if (minRes == dist[xx][yy])
            {
                if (m_x > xx)
                {
                    minRes = dist[xx][yy];
                    m_x = xx;
                    m_y = yy;
                }
                else if (m_x == xx)
                {
                    if (m_y > yy)
                    {
                        minRes = dist[xx][yy];
                        m_x = xx;
                        m_y = yy;
                    }
                }
            }
        }

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] > s)
            {
                continue;
            }
            else
            {
                if (dist[nx][ny] == 0)
                {
                    q.push({nx, ny});
                    dist[nx][ny] = dist[xx][yy] + 1;
                }
                else if (dist[nx][ny] > dist[xx][yy] + 1)
                {
                    dist[nx][ny] = dist[xx][yy] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    if (minRes != 100)
    {
        res += minRes;
        st_x = m_x;
        st_y = m_y;
        arr[m_x][m_y] = 0;
        cnt++;

        if (cnt == s)
        {
            s++;
            cnt = 0;
        }

        memset(dist, 0, sizeof(dist));
        BFS(st_x, st_y);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 9)
            {
                st_x = i;
                st_y = j;
                arr[i][j] = 0;
            }
        }
    }

    BFS(st_x, st_y);
    cout << res;

    return 0;
}
