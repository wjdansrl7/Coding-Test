#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int r, c;
char arr[1001][1001];
int visited1[1001][1001];
int visited2[1001][1001];
vector<pair<int, int>> fire;
queue<pair<int, pair<int, int>>> q1;
queue<pair<int, pair<int, int>>> q2;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minheap;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y, int dist)
{
    q2.push({dist, {x, y}});

    visited2[x][y] = dist;

    while (!q2.empty())
    {
        int curr_x = q2.front().second.first;
        int curr_y = q2.front().second.second;
        int curr_dist = q2.front().first;

        q2.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || nx > r || ny < 1 || ny > c)
            {
                minheap.push({curr_dist, {curr_x, curr_y}});
                continue;
            }
            else
            {
                if (arr[nx][ny] == '#' || visited2[nx][ny] != 0)
                {
                    continue;
                }

                q2.push({curr_dist + 1, {nx, ny}});
                visited2[nx][ny] = curr_dist + 1;
            }
        }
    }
}

void FireBfs(vector<pair<int, int>> fire, int dist)
{
    for (int i = 0; i < fire.size(); i++)
    {
        int x = fire[i].first;
        int y = fire[i].second;

        q1.push({dist, {x, y}});

        visited1[x][y] = dist;

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

                if (nx < 1 || nx > r || ny < 1 || ny > c || arr[nx][ny] == '#')
                {
                    continue;
                }
                else
                {
                    if (visited1[nx][ny] == 0)
                    {
                        q1.push({curr_dist + 1, {nx, ny}});
                        visited1[nx][ny] = curr_dist + 1;
                    }
                    else
                    {
                        if (visited1[nx][ny] > curr_dist + 1)
                        {
                            q1.push({curr_dist + 1, {nx, ny}});
                            visited1[nx][ny] = curr_dist + 1;
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int res = 0;
    int Jx, Jy;

    cin >> r >> c;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'F')
            {
                fire.push_back({i, j});
            }
            if (arr[i][j] == 'J')
            {
                Jx = i;
                Jy = j;
            }
            if (arr[i][j] == '#')
            {
                visited1[i][j] = -1;
                visited2[i][j] = -1;
            }
        }
    }
    FireBfs(fire, 1);
    bfs(Jx, Jy, 1);

    while (!minheap.empty())
    {
        if (visited1[minheap.top().second.first][minheap.top().second.second] == 0)
        {
            res = minheap.top().first;
            break;
        }
        else
        {
            if (minheap.top().first < visited1[minheap.top().second.first][minheap.top().second.second])
            {
                res = minheap.top().first;
                break;
            }
        }
        minheap.pop();
    }

    if (res == 0)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        cout << res << '\n';
    }

    return 0;
}
