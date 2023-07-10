#include <iostream>
#include <vector>
#include <set>
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
        vector<long long> maxRow(n + 1, 0);
        vector<long long> maxCol(m + 1, 0);
        set<long long> maxValues;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> bug[i][j];
                maxRow[i] = max(maxRow[i], bug[i][j]);
                maxCol[j] = max(maxCol[j], bug[i][j]);
            }
        }

        long long tmp = 0;
        for (int i = 0; i < q; i++)
        {
            int r, c;
            long long x;
            cin >> r >> c >> x;

            bug[r][c] = x;
            maxRow[r] = max(maxRow[r], x);
            maxCol[c] = max(maxCol[c], x);
        }

        maxValues.insert(maxRow.begin(), maxRow.end());
        maxValues.insert(maxCol.begin(), maxCol.end());

        tmp = m + n - maxValues.size();

        cout << "#" << tc << " " << tmp << '\n';
    }

    return 0;
}
