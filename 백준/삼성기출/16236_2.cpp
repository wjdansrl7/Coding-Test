#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
using namespace std;

int n;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int arr[30][30];
int dist[30][30] = {
    0,
};
int st_x, st_y, s = 2;
queue<pair<int, int>> q;
int res = 0, cnt = 0;

void BFS(int x, int y)
{
    int m_x = x, m_y = y;
    int minRes = 10000;
    q.push({x, y});

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        int dd = dist[xx][yy];

        if (arr[xx][yy] != 0 && arr[xx][yy] < s)
        {
            if (minRes > dd)
            {
                minRes = dd;
                m_x = xx;
                m_y = yy;
            }
            else if (minRes == dd)
            {
                if (m_x > xx)
                {
                    m_x = xx;
                    m_y = yy;
                }
                else if (m_x == xx)
                {
                    if (m_y > yy)
                    {
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

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            {
                continue;
            }
            else
            {
                if (arr[nx][ny] <= s)
                {
                    if (dist[nx][ny] == 0)
                    {
                        dist[nx][ny] = dist[xx][yy] + 1;
                        q.push({nx, ny});
                    }
                    else
                    {
                        if (dist[nx][ny] > dist[xx][yy] + 1)
                        {
                            dist[nx][ny] = dist[xx][yy] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    if (minRes != 10000)
    {
        res += minRes;
        cnt++;

        st_x = m_x;
        st_y = m_y;
        arr[st_x][st_y] = 0;

        if (cnt == s)
        {
            s++;
            cnt = 0;
        }

        memset(dist, 0, sizeof(dist));
        // dist[st_x][st_y] = minRes;
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
