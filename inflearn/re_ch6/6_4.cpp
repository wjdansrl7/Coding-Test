#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int l, n;
vector<pair<int, int>> p;

int res = INT_MIN;
void exe(int L, int depth, int maxDepth)
{
    if (depth == l)
    {
        res = max(res, maxDepth);
        return;
    }
    else
        for (int i = L; i < n; i++)
        {
            if (depth + p[i].first <= l)
                exe(i + 1, depth + p[i].first, min(maxDepth, p[i].second));
        }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);

    cin >> l >> n;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;

        p.push_back({a, b});
    }

    exe(0, 0, INT_MAX);

    cout << res;

    return 0;
}
