#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int s, e, k;
int res = INT_MAX;
int dx[] = {1, -1, 5};
vector<int> v(10001, INT_MAX);

void DFS(int x, int n)
{
    if (x == e)
    {
        res = min(res, n);
    }
    else
    {
        if (n >= res)
        {
            return;
        }

        // if (n >= res || x > 10000 || x < 0)
        // {
        //     return;
        // }

        for (int i = 0; i < 3; i++)
        {
            if (x + dx[i] <= 10000 && x + dx[i] >= 1 && v[x + dx[i]] != -1)
            {
                if (v[x + dx[i]] > n + 1)
                {
                    v[x + dx[i]] = n + 1;
                    DFS(x + dx[i], n + 1);
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in3.txt", "r", stdin);

    cin >> s >> e >> k;

    int x;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        v[x] = -1;
    }

    DFS(s, 0);
    // cout << res;
    cout << v[e];

    return 0;
}
