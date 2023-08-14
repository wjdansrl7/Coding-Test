#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<pair<int, int>> v;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in1.txt", "r", stdin);

    int w, h, t, s;
    cin >> w >> h >> t >> s;

    int x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }

    int res = INT_MIN;
    for (int i = 0; i < t; i++)
    {
        int xx = v[i].first;
        for (int j = 0; j < t; j++)
        {
            int yy = v[j].second;
            int cnt = 0;
            for (int k = 0; k < t; k++)
            {
                if (v[k].first >= xx && v[k].second >= yy)
                {
                    int yy2 = v[j].second + s;
                    int xx2 = v[i].first + s;

                    if (xx2 > w)
                    {
                        xx2 = w;
                    }
                    if (yy2 > h)
                    {
                        yy2 = h;
                    }

                    if (v[k].first <= xx2 && v[k].second <= yy2)
                        cnt++;
                }
            }
            res = max(res, cnt);
        }
    }
    cout << res << '\n';

    return 0;
}
