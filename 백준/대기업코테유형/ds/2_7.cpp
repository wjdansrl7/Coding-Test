#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
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

        vector<int> col(n + 1, 0);
        vector<int> row(m + 1, 0);

        long long cnt;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> cnt;

                // row[j] = max(row[j], cnt);
                // col[i] = max(col[i], cnt);
                if (row[j] < cnt)
                    row[j] = cnt;
                if (col[i] < cnt)
                    col[i] = cnt;
            }
        }

        int r, c;
        long long x;
        int res = 0;
        for (int i = 0; i < q; i++)
        {
            cin >> r >> c >> x;

            if (row[c] < x)
                row[c] = x;
            if (col[r] < x)
                col[r] = x;

            if (col[r] == x || row[c] == x)
            {
                res++;
            }
        }

        cout << "#" << tc << " " << n + m - res << '\n';
    }

    return 0;
}
