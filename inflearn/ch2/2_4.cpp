#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[1001][1001];
bool visited1[1001][1001];
bool visited2[1001][1001];
vector<pair<int, int>> strawberry;
queue<pair<int, pair<int, int>>> q;
queue<pair<int, pair<int, int>>> q2;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int w, h;
int dst_x, dst_y;
int res = INT_MAX;

void bfs2(int st_x, int st_y, int dst_x, int dst_y, int dist);

void bfs1(int x, int y, int st_x, int st_y)
{
    visited1[x][y] = true;
    q.push({0, {x, y}});

    while (!q.empty())
    {
        int curr_x = q.front().second.first;
        int curr_y = q.front().second.second;
        int dist = q.front().first;
        q.pop();

        if (st_x == curr_x && st_y == curr_y)
        {
            if (dist < res)
            {
                bfs2(st_x, st_y, dst_x, dst_y, dist);
            }
        }

        if (dist >= res)
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || nx > h || ny < 1 || ny > w || arr[nx][ny] == 1 || arr[nx][ny] == 3 || visited1[nx][ny])
            {
                continue;
            }
            else
            {
                q.push({dist + 1, {nx, ny}});
                visited1[nx][ny] = true;
            }
        }
    }
}

void bfs2(int st_x, int st_y, int dst_x, int dst_y, int dist)
{
    // cout << st_x << " " << st_y << '\n';
    visited2[st_x][st_y] = true;
    q2.push({dist, {st_x, st_y}});

    while (!q2.empty())
    {
        int curr_x = q2.front().second.first;
        int curr_y = q2.front().second.second;
        int dist2 = q2.front().first;

        q2.pop();

        if (dst_x == curr_x && dst_y == curr_y)
        {
            if (res > dist2)
            {
                res = dist2;
            }
        }

        if (dist2 >= res)
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || nx > h || ny < 1 || ny > w || arr[nx][ny] == 1 || visited2[nx][ny])
            {
                continue;
            }
            else
            {
                q2.push({dist2 + 1, {nx, ny}});
                visited2[nx][ny] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    freopen("in5.txt", "r", stdin);

    cin >> w >> h;
    int x, y;

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 4) // 산딸기의 위치
            {
                strawberry.push_back({i, j});
            }
            if (arr[i][j] == 2) // 영희
            {
                x = i;
                y = j;
            }
            if (arr[i][j] == 3) // 기사
            {
                dst_x = i;
                dst_y = j;
            }
        }
    }

    for (int i = 0; i < strawberry.size(); i++)
    {
        memset(visited1, 0, sizeof(visited1));
        memset(visited2, 0, sizeof(visited2));
        while (!q.empty())
        {
            q.pop();
        }
        while (!q2.empty())
        {
            q2.pop();
        }

        bfs1(x, y, strawberry[i].first, strawberry[i].second);
    }

    cout << res << '\n';

    return 0;
}
