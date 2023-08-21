#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int n, d, k;
int res = INT_MIN;

void dfs(int L, int s, int bit, vector<int> &st, vector<int> &Pow)
{
    if (L == k)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if ((st[i] & bit) == st[i])
            {
                cnt++;
            }
        }

        res = max(res, cnt);

        return;
    }
    else
    {
        for (int i = s; i < d; i++)
        {
            dfs(L + 1, i + 1, bit + Pow[i], st, Pow);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in5.txt", "r", stdin);

    cin >> n >> d >> k;
    vector<int> Pow(15, 0), st(n + 1, 0);

    Pow[0] = 1;
    for (int i = 1; i < 15; i++)
    {
        Pow[i] = Pow[i - 1] * 2;
        // Pow[i] = pow(2, i);
    }

    int k, u;
    for (int i = 0; i < n; i++)
    {
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            cin >> u;
            st[i] += Pow[u - 1];
        }
    }

    dfs(0, 0, 0, st, Pow);
    cout << res << '\n';

    return 0;
}
