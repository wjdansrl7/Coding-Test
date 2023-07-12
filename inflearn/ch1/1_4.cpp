#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    int n;
    cin >> n;

    vector<pair<int, int>> p;

    int ab1, ab2;
    for (int i = 0; i < n; i++)
    {
        cin >> ab1 >> ab2;
        p.push_back({ab1, ab2});
    }

    vector<int> white(n, 0);

    for (int i = n / 2; i < n; i++)
    {
        white[i] = 1;
    }

    int minRes = 987654321;
    do
    {
        long long res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (white[i])
            {
                res1 += p[i].first;
            }
            else
            {
                res2 += p[i].second;
            }
        }
        int diff = abs(res1 - res2);

        if (minRes > diff)
            minRes = diff;

    } while (next_permutation(white.begin(), white.end()));

    cout << minRes << '\n';

    return 0;
}
