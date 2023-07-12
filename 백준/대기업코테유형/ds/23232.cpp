#include <iostream>
#include <vector>
#include <queue>
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
        priority_queue<int> pq;
        int tmp = 0;

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

        for (int j = 1; j <= n; j++)
        {
            pq.push(col[j]);
        }
        for (int j = 1; j <= m; j++)
        {
            pq.push(row[j]);
        }

        while (!pq.empty())
        {
            int curr = pq.top();
            pq.pop();
            if (pq.top() == curr && !pq.empty())
            {
                tmp++;
                pq.pop();
            }
        }

        int r, c;
        long long x;
        long long res = 0;
        for (int i = 0; i < q; i++)
        {
            long long result = 0;

            cin >> r >> c >> x;

            if (row[c] < x)
                row[c] = x;
            if (col[r] < x)
                col[r] = x;

            if (col[r] == x || row[c] == x)
            {
                for (int j = 1; j <= n; j++)
                {
                    pq.push(col[j]);
                }
                for (int j = 1; j <= m; j++)
                {
                    pq.push(row[j]);
                }

                while (!pq.empty())
                {
                    int curr = pq.top();
                    pq.pop();
                    if (pq.top() == curr && !pq.empty())
                    {
                        result++;
                        pq.pop();
                    }
                }
                res += result;
            }
            else
            {
                res += tmp;
            }
            tmp = result;
        }
        cout << "#" << tc << " " << res << '\n';
    }

    return 0;
}