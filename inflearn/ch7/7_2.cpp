#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

bool visited[10001] = {
    false,
};
int dx[] = {-1, 1, 5};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in2.txt", "r", stdin);

    int s, e, k;
    int res = INT_MAX;
    queue<pair<int, int>> q;

    cin >> s >> e >> k;

    int x;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        visited[x] = true;
    }

    q.push({s, 0});
    visited[s] = true;
    visited[e] = false;

    while (!q.empty())
    {
        int curr = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (curr == e)
        {
            res = min(res, cnt);
            break;
        }

        for (int i = 0; i < 3; i++)
        {
            int xx = curr + dx[i];

            if (!visited[xx] && (xx <= 10000) && (xx >= 1))
            {
                q.push({xx, cnt + 1});
                visited[xx] = true;
            }
        }
    }

    cout << res << '\n';

    return 0;
}
