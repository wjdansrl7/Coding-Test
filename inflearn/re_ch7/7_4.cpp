#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, st, et;
vector<pair<int, long long>> v[10001];
queue<int> q;

int Can(int mid)
{
    vector<int> ch(n + 1, 0);
    ch[st] = 1;
    q.push(st);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto x : v[cur])
        {
            if (ch[x.first] == 0 && x.second >= mid)
            {
                ch[x.first] = 1;
                q.push(x.first);
            }
        }
    }
    return ch[et];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);

    cin >> n >> m;
    int a, b;
    long long c;
    int lt = 1, rt = INT_MIN;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});

        if (rt < c)
            rt = c;
    }

    cin >> st >> et;

    long long res;
    while (lt <= rt)
    {
        int mid = (lt + rt) / 2;

        if (Can(mid))
        {
            lt = mid + 1;
            res = mid;
        }
        else
        {
            rt = mid - 1;
        }
    }

    cout << res;

    return 0;
}
