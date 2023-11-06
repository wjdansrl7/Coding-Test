#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <map>
using namespace std;

// 78%

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

int n, m, k;
char pan[11][11];
int res;
queue<pair<string, pair<int, int>>> q;
map<string, int> result;
// stack<pair<string, pair<int, int>>> stk;

void bfs(int x, int y, string target, string s)
{
    q.push({s, {x, y}});
    // stk.push({s, {x, y}});
    while (!q.empty())
    {
        int xx = q.front().second.first;
        int yy = q.front().second.second;
        string ss = q.front().first;

        q.pop();

        if (ss == target)
        {
            res++;
            continue;
        }

        for (int i = 0; i < 8; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 1)
                nx = n;
            if (nx > n)
                nx = 1;
            if (ny < 1)
                ny = m;
            if (ny > m)
                ny = 1;

            if (target[ss.size()] == pan[nx][ny])
                q.push({ss + pan[nx][ny], {nx, ny}});
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    string str;

    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
            pan[i][j + 1] = str[j];
    }

    string target;
    for (int i = 0; i < k; i++)
    {
        res = 0;
        cin >> target;
        result.insert({target, 0});
    }
    for (int j = 1; j <= n; j++)
        for (int k = 1; k <= m; k++)
            if (pan[j][k] == target[0])
            {
                string s = "";
                s.push_back(pan[j][k]);
                bfs(j, k, target, s);
            }
    cout << res << '\n';

    return 0;
}
