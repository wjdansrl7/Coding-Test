#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n;

    vector<long long> t(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    cin >> k;

    vector<long long> sT(t);
    sort(sT.begin(), sT.end());

    int rest = n;
    for (int i = 1; i <= n; i++)
    {
        if (k < (sT[i] - sT[i - 1]) * rest)
        {
            int index = k % rest;
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (t[j] >= sT[i])
                {
                    if (cnt == index)
                    {
                        cout << j << '\n';
                        return 0;
                    }
                    cnt++;
                }
            }
        }
        else
        {
            k -= (sT[i] - sT[i - 1]) * rest;
            rest--;
        }
    }
    cout << -1 << '\n';

    return 0;
}
