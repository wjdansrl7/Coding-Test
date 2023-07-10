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

        long long val, maxCnt = -1;
        int maxIdx;
        for (int i = 1; i <= n; i++)
        {
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
            col[n + 1].push_back({maxIdx, maxCnt});
        }
    }

    return 0;
}
