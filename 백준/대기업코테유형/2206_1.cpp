#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
using namespace std;

int n, m;
int arr[1001][1001];
deque<pair<int, pair<int, int>>> q;
priority_queue<pair<int, pair<int, int>>> pq;

bool visited[1001][1001];
int res = 987654321;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y)
{
    visited[x][y] = true;
    q.push_back({1, {x, y}});
    // q.push_back({x, {y, 1}});

    while (!q.empty())
    {
        int curr_x = q.front().second.first;
        int curr_y = q.front().second.second;
        int curr_cnt = q.front().first;
        // int curr_x = q.front().first;
        // int curr_y = q.front().second.first;
        // int curr_cnt = q.front().second.second;
        q.pop_front();

        if (curr_x == n && curr_y == m)
        {
            res = min(res, curr_cnt);
            continue;
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
                    // pq.push({curr_cnt, {nx, ny}}); // 1인점은 경로에 포함하지 않았다.(이전까지의 경로만 더한 것)
                    pq.push({nx, {ny, curr_cnt}});
                    visited[nx][ny] = true;
                    continue;
                }
                visited[nx][ny] = true;
                q.push_back({curr_cnt + 1, {nx, ny}});
            }
        }
    }
}

void bfs2()
{
    while (!pq.empty())
    {
        memset(visited, 0, sizeof(visited));
        // int start_x = pq.top().second.first;
        // int start_y = pq.top().second.second;
        // int start_cnt = pq.top().first + 1;
        int start_x = pq.top().first;
        int start_y = pq.top().second.first;
        int start_cnt = pq.top().second.second + 1;
        pq.pop();

        visited[start_x][start_y] = true;
        q.push_back({start_cnt, {start_x, start_y}});

        while (!q.empty())
        {
            int curr_x = q.front().second.first;
            int curr_y = q.front().second.second;
            int curr_cnt = q.front().first;
            q.pop_front();

            if (curr_x == n && curr_y == m)
            {
                res = min(res, curr_cnt);
                continue;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = curr_x + dx[i];
                int ny = curr_y + dy[i];

                if (nx < 1 || nx > n || ny < 1 || ny > m || visited[nx][ny] || arr[nx][ny] == 1)
                {
                    continue;
                }
                else
                {
                    visited[nx][ny] = true;
                    q.push_back({curr_cnt + 1, {nx, ny}});
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

    cin >> n >> m;

    string str;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;

        for (int j = 1; j <= str.size(); j++)
        {
            arr[i][j] = int(str[j - 1]) - '0';
        }
    }

    bfs(1, 1);

    bfs2();

    if (res == 987654321)
    {
        cout << -1 << '\n';
    }
    else
        cout << res << '\n';

    return 0;
}
