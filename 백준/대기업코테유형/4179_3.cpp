#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int r, c;
queue<pair<int, pair<int, int>>> q1;
queue<pair<int, pair<int, int>>> q2;
int visited1[1001][1001];
int visited2[1001][1001];

char arr[1001][1001];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int res;

void bfs1(int x, int y, int dist)
{
    q1.push({dist, {x, y}});
    visited1[x][y] = dist;
    if (dist <)
    {
        /* code */
    }

    while (!q1.empty())
    {
        int curr_x = q1.front().second.first;
        int curr_y = q1.front().second.second;
        int curr_dist = q1.front().first;

        q1.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || nx > r || ny < 1 || ny > c || visited1[nx][ny] != 0)
            {
                continue;
            }
            else
            {
                q1.push({curr_dist + 1, {nx, ny}});
                visited1[nx][ny] = curr_dist + 1;
            }
        }
    }
}

void bfs2(int x, int y, int dist)
{
    q1.push({dist, {x, y}});
    visited2[x][y] = dist;

    while (!q1.empty())
    {
        int curr_x = q1.front().second.first;
        int curr_y = q1.front().second.second;
        int curr_dist = q1.front().first;

        q1.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || nx > r || ny < 1 || ny > c || visited2[nx][ny] != 0)
            {
                continue;
            }
            else
            {
                q1.push({curr_dist + 1, {nx, ny}});
                visited2[nx][ny] = curr_dist + 1;
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

    int Jx, Jy, Fx, Fy;
    res = 987654321;

    vector<pair<int, int>> v;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'J')
            {
                Jx = i;
                Jy = j;
            }
            if (arr[i][j] == 'F')
            {
                // Fx = i;
                // Fy = j;
                v.push_back({i, j});
            }
            if (arr[i][j] == '#')
            {
                visited1[i][j] = -1;
                visited2[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        bfs1(v[i].first, v[i].second, 1);
    }

    // bfs1(Fx, Fy, 1);
    bfs2(Jx, Jy, 1);

    // for (int i = 1; i <= r; i++)
    // {
    //     for (int j = 1; j <= c; j++)
    //     {
    //         cout << visited1[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // for (int i = 1; i <= r; i++)
    // {
    //     for (int j = 1; j <= c; j++)
    //     {
    //         cout << visited2[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i == 1 && visited1[i][j] != -1)
            {
                if (visited1[i][j] == 0) //  도달 X
                {
                    if (res > visited2[i][j])
                    {
                        res = visited2[i][j];
                    }
                }
                else
                {
                    if (visited2[i][j] < visited1[i][j])
                    {
                        if (res > visited2[i][j])
                        {
                            res = visited2[i][j];
                        }
                    }
                }
            }
            if (i == r && visited1[i][j] != -1)
            {
                if (visited1[i][j] == 0) //  도달 X
                {
                    if (res > visited2[i][j])
                    {
                        res = visited2[i][j];
                    }
                }
                else
                {
                    if (visited2[i][j] < visited1[i][j])
                    {
                        if (res > visited2[i][j])
                        {
                            res = visited2[i][j];
                        }
                    }
                }
            }
            if (j == 1 && visited1[i][j] != -1)
            {
                if (visited1[i][j] == 0) //  도달 X
                {
                    if (res > visited2[i][j])
                    {
                        res = visited2[i][j];
                    }
                }
                else
                {
                    if (visited2[i][j] < visited1[i][j])
                    {
                        if (res > visited2[i][j])
                        {
                            res = visited2[i][j];
                        }
                    }
                }
            }
            if (j == c && visited1[i][j] != -1)
            {
                if (visited1[i][j] == 0) //  도달 X
                {
                    if (res > visited2[i][j])
                    {
                        res = visited2[i][j];
                    }
                }
                else
                {
                    if (visited2[i][j] < visited1[i][j])
                    {
                        if (res > visited2[i][j])
                        {
                            res = visited2[i][j];
                        }
                    }
                }
            }
        }
    }

    if (res == 987654321)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        cout << res << '\n';
    }

    return 0;
}
