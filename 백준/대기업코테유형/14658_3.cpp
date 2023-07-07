#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, l, k;
    cin >> n >> m >> l >> k;

    vector<pair<int, int>> star;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        star.push_back({x, y});
    }

    int maxRes = -1;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int curr_x = star[i].first;
            int curr_y = star[j].second;

            int cnt = 0;
            for (int u = 0; u < k; u++)
            {
                if (star[u].first >= curr_x && star[u].first <= curr_x + l && star[u].second >= curr_y && star[u].second <= curr_y + l)
                {
                    cnt++;
                }
            }
            maxRes = max(cnt, maxRes);
        }
    }

    cout << k - maxRes << '\n';

    return 0;
}
