#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

int n, l, r;

int arr[51][51];
int tmp[51][51];
bool visited[51][51];
queue<pair<int, pair<int, int>>> q;
queue<pair<int, int>> v;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y)
{
    visited[x][y] = true;
    q.push({arr[x][y], {x, y}});
    int sum = 0;
    int qCnt = 1;

    while (!q.empty())
    {
        int curr_x = q.front().second.first;
        int curr_y = q.front().second.second;
        sum += q.front().first;

        v.push({curr_x, curr_y});
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            int weight = abs(arr[nx][ny] - arr[curr_x][curr_y]);

            if (weight < l || weight > r)
            {
                continue;
            }
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
            {
                continue;
            }
            else
            {
                q.push({arr[nx][ny], {nx, ny}});
                visited[nx][ny] = true;
                qCnt++;
            }
        }
    }

    while (!v.empty())
    {
        tmp[v.front().first][v.front().second] = sum / qCnt;
        v.pop();
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int day = 0;
    while (1)
    {
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = tmp[i][j];
                tmp[i][j] = 0;
            }
        }

        if (cnt == n * n)
        {
            break;
        }
        else
        {
            memset(visited, 0, sizeof(visited));
        }
        day++;
    }

    cout << day << '\n';

    return 0;
}
