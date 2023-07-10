#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int n, m, q;
        cin >> n >> m >> q;

        vector<vector<long long>> bug(n + 1, vector<long long>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> bug[i][j];
            }
        }

        vector<long long> maxRow(n + 1, 0);
        vector<long long> maxCol(m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                maxRow[i] = max(maxRow[i], bug[i][j]);
                maxCol[j] = max(maxCol[j], bug[i][j]);
            }
        }

        long long tmp = 0;
        long long tmp2 = 0;
        set<long long> a;
        for (int i = 0; i < q; i++)
        {
            int r, c;
            long long x;
            a.clear();
            cin >> r >> c >> x;

            bug[r][c] = x;
            maxRow[r] = max(maxRow[r], x);
            maxCol[c] = max(maxCol[c], x);

            if (maxRow[r] == x || maxCol[c] == x)
            {
                for (int j = 1; j <= n; j++)
                {
                    a.insert(maxRow[j]);
                }

                for (int j = 1; j <= m; j++)
                {
                    a.insert(maxCol[j]);
                }

                tmp += m + n - a.size();
            }
            else
            {
                tmp += tmp2;
            }

            tmp2 = m + n - a.size();
        }

        cout << "#" << tc << " " << tmp << '\n';
    }

    return 0;
}
