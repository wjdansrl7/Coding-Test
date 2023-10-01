#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v;

    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    int l = 1;
    int r = 100000;

    int res;
    while (l <= r)
    {
        int flag = 0;
        int mid = (l + r) / 2;

        if (v[0] > mid)
        {
            flag = 1;
        }
        for (int i = 0; i < m - 1; i++)
        {
            if (v[i + 1] - v[i] > mid * 2)
            {
                flag = 1;
                break;
            }
        }
        if (n - v[m - 1] > mid)
        {
            flag = 1;
        }

        if (!flag)
        {
            r = mid - 1;
            res = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << res << '\n';

    return 0;
}
