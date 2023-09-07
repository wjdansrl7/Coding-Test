#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, s, e;
vector<pair<int, int>> graph[10001];

int Can(int mid)
{
    vector<int> ch(n + 1, 0);
    queue<int> Q;
    ch[s] = 1;
    Q.push(s);
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();

        /*
        for (int i = 0; i < graph[v].size(); i++)
        {
            if (graph[v][i].second >= mid && ch[graph[v][i].first] == 0)
            {
                ch[graph[v][i].first] = 1;
                Q.push(graph[v][i].first);
            }
        }
        */
        for (auto x : graph[v])
        {
            if (x.second >= mid && ch[x.first] == 0)
            {
                ch[x.first] = 1;
                Q.push(x.first);
            }
        }
    }

    return ch[e];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int a, b, c, high;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
        high = max(high, c);
    }
    cin >> s >> e;
    int lt = 1;
    int rt = high;
    int res = 0;
    while (lt <= rt)
    {
        int mid = (lt + rt) / 2;
        if (Can(mid))
        {
            res = mid;
            lt = mid + 1;
        }
        else
            rt = mid - 1;
    }
    cout << res;
    return 0;
}
