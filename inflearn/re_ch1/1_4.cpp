#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);

    int n;
    cin >> n;
    vector<pair<int, int>> ab;
    vector<int> team;

    for (int i = 0; i < n / 2; i++)
    {
        team.push_back(0);
    }
    for (int i = n / 2; i < n; i++)
    {
        team.push_back(1);
    }

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        ab.push_back({a, b});
    }

    // 1: 흰, 0, 블
    int res = INT_MAX;
    do
    {
        int wSum = 0, bSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (team[i] == 1)
            {
                wSum += ab[i].first;
            }
            else
                bSum += ab[i].second;
        }
        res = min(res, abs(wSum - bSum));

    } while (next_permutation(team.begin(), team.end()));

    cout << res << '\n';

    return 0;
}
