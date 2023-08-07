#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    stack<pair<int, int>> stk;
    cin >> n >> m;

    // vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    vector<pair<int, int>> v[n + 1];
    vector<int> res(n, INT_MAX);

    int a, b;
    long long c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        // v[a][b] = c;
        // v[b][a] = c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    int st, et;
    cin >> st >> et;

    for (int i = 0; i < v[st].size(); i++)
    {
        stk.push({v[st][i].first, v[st][i].second});
        res[v[st][i].first] = v[st][i].second;
    }

    while (!stk.empty())
    {
        int curr = stk.top().first;
        int dist = stk.top().second;
        stk.pop();

        if (curr == et)
        {
            continue;
        }

        for (int i = 0; i < v[curr].size(); i++)
        {
            int tmp = min(dist, v[curr][i].second);
            res[v[curr][i].first] = max(res[v[curr][i].first], tmp);
            stk.push({v[curr][i].first, v[curr][i].second});
        }
    }

    cout << res[et] << '\n';

    return 0;
}