#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#define INF 1e10
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    deque<long long> q;
    cin >> n;

    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push_back(x);
    }

    int l = 0, r = n - 1;
    long long ans1 = q[l], ans2 = q[r];
    long long sum = INF;

    while (l < r)
    {
        if (sum > abs(q[l] + q[r]))
        {
            sum = abs(q[l] + q[r]);
            ans1 = q[l], ans2 = q[r];
        }

        if (q[l] + q[r] < 0)
        {
            l++;
        }
        else if (q[l] + q[r] > 0)
        {
            r--;
        }
        else if (q[l] + q[r] == 0)
        {
            ans1 = q[l], ans2 = q[r];
            break;
        }
    }

    cout << ans1 << " " << ans2 << '\n';

    return 0;
}
