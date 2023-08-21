#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> seats(n + 2, 0);
    vector<int> res(n + 2, 0), res2(n + 2, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> seats[i];
    }
    res[0] = res[n + 1] = 1000;
    res2[0] = res2[n + 1] = 1000;

    for (int i = 1; i <= n; i++)
    {
        if (seats[i] == 1)
        {
            res[i] = 0;
        }
        else
        {
            res[i] = res[i - 1] + 1;
        }
    }

    int ans = INT_MIN;
    for (int i = n; i > 0; i--)
    {
        if (seats[i] == 1)
        {
            res2[i] = 0;
        }
        else
        {
            res2[i] = min(res[i], res2[i + 1] + 1);
            ans = max(ans, res2[i]);
        }
    }
    cout << ans << '\n';

    return 0;
}
