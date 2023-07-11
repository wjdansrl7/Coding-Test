#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int arr[1001][1001];
bool visited[1001][1001];
deque<pair<int, int>> q;
// deque<pair<int, int>> tmp;
priority_queue<pair<int, int>> tmp;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs(int x, int y)
{
    visited[x][y] = true;
    q.push_back({x, y});
    int cnt = 0;

    while (!q.empty() || !tmp.empty())
    {
        if (q.empty())
        {
            q.push_back({tmp.top().first, tmp.top().second});
        }
        
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop_front();
        cnt++;

        if (curr_x == n && curr_y == m)
        {
            return cnt;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m || visited[nx][ny])
            {
                continue;
            }
            else
            {
                if (arr[nx][ny] == 1)
                {
                    // tmp.push_front({nx, ny});
                    tmp.push({nx, ny});
                    continue;
                }

                q.push_back({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    while (!tmp.empty())
    {
        int curr_x = tmp.top().first;
        int curr_y = tmp.top().second;
        tmp.pop();
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m || visited[nx][ny])
            {
                continue;
            }
            else
            {
                visited[nx][ny] = true;
                q.push_back({nx, ny});

            }
            
        }
        

    }
    

    return -1;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (bfs(1,1) == -1)
    {
        arr[tmp.top().first][tmp.top().second] = 0;
        
    }
    

    bfs(1, 1);

    return 0;
}
