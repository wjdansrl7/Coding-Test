#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[1001][1001] = {
    0,
};
int dist[2][1001][1001] = {
    0,
};
queue<pair<int, int>> q;
int h, w, x, y, dst_x, dst_y;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int res = INT_MAX;

void bfs(int start_x, int start_y, int idx)
{
    q.push({start_x, start_y});
    dist[idx][start_x][start_y] = 1;

    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        int curr_dist = dist[idx][curr_x][curr_y];

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && dist[idx][nx][ny] == 0)
            {
                if (arr[nx][ny] != 1)
                {
                    q.push({nx, ny});
                    dist[idx][nx][ny] = curr_dist + 1;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    freopen("in2.txt", "r", stdin);
    cin >> w >> h;

    vector<pair<int, int>> strberry;

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 2)
            {
                x = i;
                y = j;
            }

            if (arr[i][j] == 3)
            {
                dst_x = i;
                dst_y = j;
            }
            if (arr[i][j] == 4)
            {
                strberry.push_back({i, j});
            }
        }
    }

    bfs(x, y, 0);

    bfs(dst_x, dst_y, 1);

    for (int i = 0; i < strberry.size(); i++)
    {
        int st_x = strberry[i].first;
        int st_y = strberry[i].second;

        if (dist[0][st_x][st_y] > 0 && dist[1][st_x][st_y] > 0)
        {
            if (res > dist[0][st_x][st_y] + dist[1][st_x][st_y])
            {
                res = dist[0][st_x][st_y] + dist[1][st_x][st_y];
            }
        }
    }

    cout << res - 2 << '\n';

    return 0;
}
