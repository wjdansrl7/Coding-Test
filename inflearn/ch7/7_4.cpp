/*
위 문제는 결정 알고리즘 + bfs를 사용하는 문제이다.
문제에서는 다리를 이동할 수 있는 최대의 무게를 구하는 문제이므로
1 -> 5로 갈 수있다면 Ok -> 갈 수 있는 최대무게인 mid값을 res에 저장한다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, m, s, e;
vector<pair<int, int>> v[100001];
queue<pair<int, int>> q;

int Can(int mid)
{
    vector<int> ch(n + 1, 0);

    ch[s] = true;
    for (int i = 0; i < v[s].size(); i++)
    {
        q.push({v[s][i].first, v[s][i].second});
    }

    while (!q.empty())
    {
        int curr = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (dist >= mid && !ch[curr])
        {
            ch[curr] = 1;
            for (auto x : v[curr])
            {
                q.push({x.first, x.second});
                // ch[x.first] = true;
            }
        }
    }

    return ch[e];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    cin >> n >> m;

    int a, b;
    int c;
    int lt = 1, rt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
        rt = max(rt, c);
    }

    cin >> s >> e;

    int ans = 0;
    while (lt <= rt)
    {
        int mid = (lt + rt) / 2;

        if (Can(mid))
        {
            lt = mid + 1;
            ans = max(ans, mid);
        }
        else
            rt = mid - 1;
    }

    cout << ans << '\n';

    return 0;
}
