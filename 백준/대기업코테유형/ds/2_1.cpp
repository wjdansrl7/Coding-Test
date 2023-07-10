#include <iostream>
#include <vector>
#include <set>
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
        long long result = 0;
        // int col[200001];
        vector<pair<int, int>> col;
        cin >> n >> m >> q;

        long long cnt, maxCnt = -1;
        int maxIdx;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> cnt;
                if (maxCnt < cnt)
                {
                    maxCnt = cnt;
                    maxIdx = j;
                }
            }
            // col[i] = maxIdx;
            col.push_back({maxIdx, maxCnt});
        }

        int r, c;
        long long x;
        for (int i = 0; i < q; i++)
        {
            cin >> r >> c >> x;
            if (col[r - 1].second < x)
            {
                col[r - 1].first = c - 1;
                col[r - 1].second = x;
            }

            set<int> res;
            for (int i = 0; i < n; i++)
            {
                res.insert(col[i].first);
            }

            result += res.size();
        }

        cout << "#" << tc << " " << result << '\n';
    }

    return 0;
}
