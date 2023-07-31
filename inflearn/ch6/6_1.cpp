#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int r, c;
int arr[101][101];
bool visited[101][101];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
stack<pair<int, int>> stk;

void dfs(int x, int y)
{
    visited[x][y] = true;
    stk.push({x, y});

    while (!stk.empty())
    {
        int xx = stk.top().first;
        int yy = stk.top().second;

        stk.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny])
            {
                if (arr[nx][ny] == 1)
                {
                    stk.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in5.txt", "r", stdin);
    int res = 0;
    cin >> r >> c;

    string str;

    for (int i = 0; i < r; i++)
    {
        cin >> str;

        for (int j = 0; j < c; j++)
        {
            if (str[j] == '.')
            {
                arr[i][j] = 0;
            }
            else
                arr[i][j] = 1;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                dfs(i, j);
                res++;
            }
        }
    }

    cout << res << '\n';
    return 0;
}
