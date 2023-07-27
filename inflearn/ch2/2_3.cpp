#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    long long t;

    cin >> n;

    vector<long long> init_p(n + 1);
    vector<pair<long long, int>> p;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        init_p.push_back(t);
        p.push_back({t, i + 1});
    }

    cin >> k;

    sort(p.begin(), p.end());

    // long long sum = 0;
    long long rotation = k / p.size();
    long long num = k % p.size();

    vector<int> ex_idx;

    int u = 0;

    for (int i = 0; i < p.size(); i++)
    {
        if (rotation >= p[i].first)
        {
            num += rotation - p[i].first;
            init_p[p[i].second - 1] = 0;
            // init_p[p[i].second - 1] = -1;
            // u++;
            // ex_idx.push_back(p[i].second);
        }
    }

    int cnt2 = 0;
    for (int i = 0; i < init_p.size(); i++)
    {
        if (init_p[i] == 0)
            cnt2++;
    }

    for (int i = 0; i < num % (init_p.size() - cnt2); i++)
    {
    }

    // for (int i = 0; i < num; i++)
    // {
    //     if (init_p[i] == 0)
    //     {
    //         continue;
    //     }

    // }

    return 0;
}
