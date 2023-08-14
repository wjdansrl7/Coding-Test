#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, m, r;
vector<pair<int, pair<int, int>>> st;
int res = INT_MIN;

bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{
    return a.second.first < b.second.first;
}

void dfs(int L, int sum)
{
    // sum += st[L].first;
    int s = st[L].second.first;
    int e = st[L].second.second;

    for (int i = L + 1; i < m; i++)
    {
        if (st[i].second.first < n && st[i].second.first >= e + r)
        {
            sum += st[i].first;
            dfs(i, sum);
            sum -= st[i].first;
        }
    }

    res = max(res, sum);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in3.txt", "r", stdin);

    cin >> n >> m >> r;

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;

        st.push_back({c, {a, b}});
    }

    sort(st.begin(), st.end(), cmp);

    for (int i = 0; i < m; i++)
    {
        dfs(i, st[i].first);
    }

    cout << res << '\n';

    return 0;
}
