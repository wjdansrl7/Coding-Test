#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
int arr[26][26];
int visited[26][26];
int CountHome[625];
queue<pair<int, int>> q;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int nCount = 0;
int home = 0;

void bfs(int x, int y)
{
    visited[x][y] = true;

    q.push({x, y});
    nCount++;

    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx > 0 && nx <= N && ny > 0 && ny <= N)
            {
                if (!visited[nx][ny] && arr[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    nCount++;
                }
            }
        }
    }
    CountHome[++home] = nCount;
    nCount = 0;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, 0, sizeof(arr));
    memset(visited, 0, sizeof(visited));
    memset(CountHome, 0, sizeof(CountHome));

    cin >> N;

    string a;

    for (int i = 1; i <= N; i++)
    {
        cin >> a;

        for (int j = 0; j < N; j++)
        {
            if (a[j] == '0')
            {
                arr[i][j + 1] = 0;
            }

            else
                arr[i][j + 1] = 1;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                bfs(i, j);
            }
        }
    }

    sort(CountHome, CountHome + home);

    cout << home << endl;
    for (int i = 1; i <= home; i++)
    {
        cout << CountHome[i] << endl;
    }

    return 0;
}
