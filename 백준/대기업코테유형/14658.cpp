#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, l;
    deque<pair<int, int>> q;

    cin >> n >> m >> l >> k;

    int dx[] = {0, 0, -l, l};
    int dy[] = {-l, l, 0, 0};

    // int dx[] = {l, l, -l, -l};
    // int dy[] = {l, -l, l, -l};

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
        int curr_x = q[i].first;
        int curr_y = q[i].second;

        for (int u = 0; u < 4; u++)
        {
            int nx = curr_x + dx[u];
            int ny = curr_y + dy[u];

            int cnt = 0;
            for (int j = 0; j < q.size(); j++)
            {
                if (curr_x < nx)
                {
                    if (curr_y < ny)
                    {
                        if (q[j].first <= nx && q[j].first >= curr_x && q[j].second <= ny && q[j].second >= curr_y)
                        {
                            cout << q[j].first << " " << q[j].second << " 1" << '\n';
                            cnt++;
                        }
                    }
                    else
                    {
                        if (q[j].first <= nx && q[j].first >= curr_x && q[j].second <= curr_y && q[j].second >= ny)
                        {
                            cout << q[j].first << " " << q[j].second << " 2" << '\n';

                            cnt++;
                        }
                    }
                }
                else
                {
                    if (curr_y < ny)
                    {
                        if (q[j].first <= curr_x && q[j].first >= nx && q[j].second <= ny && q[j].second >= curr_y)
                        {
                            cout << q[j].first << " " << q[j].second << " 3" << '\n';

                            cnt++;
                        }
                    }
                    else
                    {
                        if (q[j].first <= curr_x && q[j].first >= nx && q[j].second <= curr_y && q[j].second >= ny)
                        {
                            cout << q[j].first << " " << q[j].second << " 4" << '\n';

                            cnt++;
                        }
                    }
                }
            }
            cout << "============" << '\n';
            if (maxRes < cnt)
            {
                maxRes = cnt;
            }
        }
    }
    if (maxRes == 0)
    {
        cout << k << '\n';
    }
    else
        cout << k - maxRes << '\n';

    return 0;
}
