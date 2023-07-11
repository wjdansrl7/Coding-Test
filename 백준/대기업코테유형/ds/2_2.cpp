#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int n, m, q;

        cin >> n >> m >> q;

        vector<vector<int>> bug(n + 1, vector<int>(m + 1));
        vector<pair<int, int>> col[n + 1];

        long long val;

        for (int i = 1; i <= n; i++)
        {
            int maxIdx;
            long long maxCnt = -1;
            for (int j = 1; j <= m; j++)
            {
                cin >> val;
                bug[i][j] = val;

                if (maxCnt < val)
                {
                    maxCnt = val;
                    maxIdx = j;
                }
            }
            col[i].push_back({maxIdx, maxCnt});
        }

        int r, c;
        long long x;

        for (int i = 0; i < q; i++)
        {
            cin >> r >> c >> x;
            if (col[r])
            {
                /* code */
            }
            
        }
        
    }

    return 0;
}
