#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

deque<int> profit;
long long res = 0;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int n, x;
    while (T--)
    {
        cin >> n;
        res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            profit.push_back(x);
        }

        while (!profit.empty())
        {
            int maxIdx = max_element(profit.begin(), profit.end()) - profit.begin();
            int maxProfit = profit[maxIdx];

            for (int i = 0; i <= maxIdx; i++)
            {
                res += maxProfit - profit.front();
                profit.pop_front();
            }
        }

        cout << res << '\n';
    }

    return 0;
}
