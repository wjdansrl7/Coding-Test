#include <iostream>
#include <vector>
#include <set>
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

        vector<vector<long long>> bug(n + 1, vector<long long>(m + 1, 0));

        long long cnt; // 개체 수

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> cnt;
                bug[i][j] = cnt;
            }
        }

        int r, c;
        long long x;
        long long tmp = 0;

        set<long long> a;
        for (int i = 0; i < q; i++)
        {
            a.clear();
            cin >> r >> c >> x;
            bug[r][c] = x;

            for (int i = 1; i <= m; i++)
            {
                long long maxCnt2 = bug[1][i];
                for (int j = 1; j <= n; j++)
                {
                    if (maxCnt2 < bug[j][i])
                    {
                        maxCnt2 = bug[j][i];
                    }
                }
                a.insert(maxCnt2);
            }

            for (int i = 1; i <= n; i++)
            {
                long long maxCnt1 = bug[i][1];
                for (int j = 1; j <= m; j++)
                {
                    if (maxCnt1 < bug[i][j])
                    {
                        maxCnt1 = bug[i][j];
                    }
                }
                a.insert(maxCnt1);
            }

            tmp += m + n - a.size();
        }

        cout << "#" << tc << " " << tmp << '\n';
    }

    return 0;
}
