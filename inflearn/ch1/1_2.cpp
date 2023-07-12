#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in5.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int w, h, t, s; // w:가로, h:세로, t: 오렌지나무개수, s: 한변의길이
    cin >> w >> h >> t >> s;

    vector<pair<int, int>> orange;

    int x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        orange.push_back({x, y});
    }

    int maxCnt = 0;
    for (int i = 0; i < t; i++)
    {
        int curr_x = orange[i].first;

        for (int j = 0; j < t; j++)
        {
            int curr_y = orange[j].second;
            int cnt = 0;

            for (int k = 0; k < t; k++)
            {
                if (orange[k].first >= curr_x && orange[k].first <= curr_x + s && orange[k].second >= curr_y && orange[k].second <= curr_y + s)
                {
                    cnt++;
                }
            }

            maxCnt = max(maxCnt, cnt);
        }
    }

    cout << maxCnt << '\n';

    return 0;
}
