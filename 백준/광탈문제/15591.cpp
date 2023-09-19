#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> graph[n + 1];
    vector<int> ans;

    int a, b;
    long long c;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    queue<int> Q;
    long long k;
    int v;
    for (int i = 0; i < q; i++)
    {
        vector<bool> ch(n + 1);
        cin >> k >> v;
        int cnt = 0;
        Q.push(v);
        ch[v] = true;

        while (!Q.empty())
        {
            int curr = Q.front();
            Q.pop();

            for (auto v : graph[curr])
            {
                if (v.second >= k && !ch[v.first])
                {
                    ch[v.first] = true;
                    cnt++;
                    Q.push(v.first);
                }
            }
        }
        ans.push_back(cnt);
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}
