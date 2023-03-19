#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
#include <utility>
#include <cstring>

#define MAXN 101
#define max(a, b) a > b ? a : b

using namespace std;

set<int> number;
int area[MAXN][MAXN];
stack<pair<int, int>> stk;
bool visited[MAXN][MAXN];
int n;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int x, int y, int k)
{
    stk.push({x, y});

    while (!stk.empty())
    {
        int curr_x = stk.top().first;
        int curr_y = stk.top().second;

        visited[curr_x][curr_y] = true;

        stk.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > n || visited[nx][ny] || area[nx][ny] <= k)
            {
                continue;
            }

            stk.push({nx, ny});
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> area[i][j];
            number.insert(area[i][j]);
        }
    }

    number.insert(0); // 비가 오지 않는 경우

    int height = number.size();
    int nCount[height];

    memset(nCount, 0, sizeof(nCount));
    int h = 0;

    for (int k : number)
    {
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!visited[i][j] && area[i][j] > k)
                {
                    dfs(i, j, k);
                    nCount[h]++;
                }
            }
        }
        h++;
    }

    int maxCount = nCount[0];
    for (int i = 0; i < height; i++)
    {
        maxCount = max(maxCount, nCount[i]);
    }

    cout << maxCount << "\n";

    return 0;
}
