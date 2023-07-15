#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    // freopen("in2.txt", "r", stdin);

    ios_base::sync_with_stdio(false);

    int n;
    long long k;
    cin >> n;

    vector<pair<long long, int>> T(n + 1), sT(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> T[i].first;
        T[i].second = i;
    }

    sT = T;

    sort(sT.begin(), sT.end());

    cin >> k;

    int rest = T.size() - 1;
    int idx;

    for (int i = 1; i <= sT.size(); i++)
    {
        if (rest == 0)
        {
            cout << -1 << '\n';
            break;
        }

        if ((sT[i].first - sT[i - 1].first) * rest <= k)
        {
            k -= (sT[i].first - sT[i - 1].first) * rest;
            rest--;
            T[sT[i].second].first = 0;
        }
        else
        {

            idx = k % rest;
            int target = 0;
            for (int i = 1; i <= T.size(); i++)
            {
                if (T[i].first != 0)
                {
                    target++;
                }
                if (target == idx + 1)
                {
                    cout << T[i].second << '\n';
                    return 0;
                }
            }
        }
    }

    return 0;
}
