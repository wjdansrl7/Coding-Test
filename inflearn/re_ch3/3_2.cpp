#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> v(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int min1 = v[1], min2 = v[2];
    int res = 0;

    for (int i = n; i >= 1; i -= 2)
    {
        if (i == 2)
        {
            res += min2;
            break;
        }
        if (i == 3)
        {
            res += min(min2 * 2 + v[i], v[i] + v[i - 1] + min1);
            break;
        }

        else
        {
            res += min(min1 * 2 + v[i] + v[i - 1], min2 * 2 + v[i] + min1);
        }
    }

    cout << res << '\n';

    return 0;
}
