#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 101

using namespace std;

int M, N, H;
int tomato[MAXN][MAXN][MAXN];
int dist[MAXN][MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN];

int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

queue<pair<int, pair<int, int>>> q;

void bfs(int arr[MAXN][MAXN][MAXN])
{
    while (!q.empty())
    {
        int curr_x = q.front().second.first;
        int curr_y = q.front().second.second;
        int curr_z = q.front().first;

        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            int nz = curr_z + dz[i];

            if (nx < 1 || nx > N || ny < 1 || ny > M || nz < 1 || nz > H)
            {
                continue;
            }
            else
            {
                if (!visited[nz][nx][ny] && tomato[nz][nx][ny] == 0)
                {
                    dist[nz][nx][ny] = dist[curr_z][curr_x][curr_y] + 1;
                    tomato[nz][nx][ny] = 2;
                    q.push({nz, {nx, ny}});
                    visited[nz][nx][ny] = true;
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

    memset(tomato, 0, sizeof(tomato));
    memset(dist, 0, sizeof(dist));
    memset(visited, 0, sizeof(visited));

    cin >> M >> N >> H;

    for (int k = 1; k <= H; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                cin >> tomato[k][i][j];
            }
        }
    }

    for (int k = 1; k <= H; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (tomato[k][i][j] == 1 && !visited[k][i][j])
                {
                    // bfs(tomato, k, i, j);
                    visited[k][i][j] = true;
                    q.push({k, {i, j}});
                }
            }
        }
    }
    bfs(tomato);

    int maxDay = -1;

    for (int k = 1; k <= H; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (tomato[k][i][j] == 0)
                {
                    cout << -1 << "\n";
                    return 0;
                }

                if (maxDay < dist[k][i][j])
                {
                    maxDay = dist[k][i][j];
                }
            }
        }
    }

    if (maxDay == 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << maxDay << "\n";
    }

    return 0;
}
