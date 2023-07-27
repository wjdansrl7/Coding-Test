#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);

    freopen("in5.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> seat(n + 1);
    vector<int> canSeat;

    for (int i = 0; i < n; i++)
    {
        cin >> seat[i];

        if (seat[i] == 0)
        {
            canSeat.push_back(i);
        }
    }

    int res = INT_MIN;

    for (int i = 0; i < canSeat.size(); i++)
    {
        int cnt1 = 0, cnt2 = 0;
        for (int j = canSeat[i] + 1; j < n; j++)
        {
            cnt1++;
            if (seat[j] == 1)
                break;
        }

        for (int j = canSeat[i] - 1; j >= 0; j--)
        {
            cnt2++;
            if (seat[j] == 1)
                break;
        }

        if (cnt1 == 0)
        {
            if (res < cnt2)
            {
                res = cnt2;
            }
            continue;
        }
        if (cnt2 == 0)
        {
            if (res < cnt1)
            {
                res = cnt1;
            }
            continue;
        }

        if (cnt1 <= cnt2)
        {
            if (res < cnt1)
            {
                res = cnt1;
            }
        }
        else
        {
            if (res < cnt2)
            {
                res = cnt2;
            }
        }
    }

    cout << res << '\n';

    return 0;
}
