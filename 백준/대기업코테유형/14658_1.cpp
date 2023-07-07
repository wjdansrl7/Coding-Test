#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, l, k;
    deque<pair<int, int>> q;
    cin >> n >> m >> l >> k;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;

        q.push_back({x, y});
    }

    sort(q.begin(), q.end());

    int maxRes = -1;
    for (int i = 0; i < q.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < q.size(); j++)
        {
            // if (i == j)
            // {
            //     continue;
            // }

            if (abs(q[i].first - q[j].first) <= l && abs(q[i].second - q[j].second) <= l)
            {
                cout << q[j].first << " " << q[j].second << '\n';
                cnt++;
            }
        }
        cout << "====================" << '\n';
        if (maxRes < cnt)
        {
            maxRes = cnt;
        }
    }

    cout << maxRes << '\n';

    return 0;
}
