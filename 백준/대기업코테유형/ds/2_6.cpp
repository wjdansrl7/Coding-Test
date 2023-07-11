#include <iostream>
#include <vector>
#include <unordered_set>
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

                if (row[j] < cnt)
                    row[j] = cnt;
                if (col[i] < cnt)
                    col[i] = cnt;
            }
        }

        int r, c;
        long long x;
        unordered_set<int> a;
        int tmp = 0;
        long long res = 0;
        for (int i = 0; i < q; i++)
        {
            a.clear();
            cin >> r >> c >> x;

            if (row[c] < x)
                row[c] = x;
            if (col[r] < x)
                col[r] = x;

            if (col[r] == x || row[c] == x)
            {
                for (int j = 1; j <= n; j++)
                {
                    a.insert(col[j]);
                }
                for (int j = 1; j <= m; j++)
                {
                    a.insert(row[j]);
                }

                res += n + m - a.size();
            }
            else
            {
                res += n + m - tmp;
            }

            tmp = a.size();
        }
        cout << "#" << tc << " " << res << '\n';
    }

    return 0;
}