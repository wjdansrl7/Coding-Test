#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool visited[100][100];
queue<pair<pair<int, int>, int>> q;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs(vector<vector<int>> maps, int start_x, int start_y, int n, int m, int nCount)
{
    visited[start_x][start_y] = true;
    q.push(make_pair(make_pair(start_x, start_y), nCount));
    int minCount = 50000;

    while (!q.empty())
    {
        int curr_x = q.front().first.first;
        int curr_y = q.front().first.second;
        int next = q.front().second + 1;

        if (curr_x == n - 1 && curr_y == m - 1)
        {
            if (minCount > q.front().second)
                minCount = q.front().second;
        }

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            else
            {
                if (!visited[nx][ny] && maps[nx][ny] == 1)
                {
                    // q.push(make_pair(make_pair(nx, ny), nCount));
                    q.push(make_pair(make_pair(nx, ny), next));

                    visited[nx][ny] = true;
                }
            }
        }
    }

    if (minCount == 50000)
    {
        minCount = -1;
    }

    return minCount;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    memset(visited, 0, sizeof(visited));

    int n = maps.size();
    int m = maps[0].size();

    answer = bfs(maps, 0, 0, n, m, 1);

    return answer;
}