#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int r, c;
char arr[101][101];
bool visited[101][101];
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

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == '.')
            {
                continue;
            }
            else
            {
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    stk.push({nx, ny});
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    cin >> r >> c;
    vector<pair<int, int>> v;

    string str;
    for (int i = 0; i < r; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            arr[i][j] = str[j];

            if (arr[i][j] == '#')
            {
                v.push_back({i, j});
            }
        }
    }

    int res = 0;
    for (auto a : v)
    {
        if (!visited[a.first][a.second])
        {
            dfs(a.first, a.second);
            res++;
        }
    }
    cout << res;

    return 0;
}
