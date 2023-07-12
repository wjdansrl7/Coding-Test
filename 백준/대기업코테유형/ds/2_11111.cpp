#include <iostream>
#include <queue>
#include <vector>
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

        long long bug;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> bug;
                if (col[i] < bug)
                {
                    col[i] = bug;
                }
                if (row[j] < bug)
                {
                    row[j] = bug;
                }
            }
        }

        priority_queue<int> pq;

        int r, c;
        long long x, res, tmp;
        long long result = 0;

        for (int i = 0; i < q; i++)
        {
            res = 0;
            cin >> r >> c >> x;
            if (col[r] < x)
            {
                col[r] = x;
            }
            if (row[c] < x)
            {
                row[c] = x;
            }

            if (col[r] == x || row[c] == x)
            {
                for (int i = 1; i <= n; i++)
                {
                    pq.push(col[i]);
                }

                for (int i = 1; i <= m; i++)
                {
                    pq.push(row[i]);
                }

                while (!pq.empty())
                {
                    int curr = pq.top();
                    pq.pop();

                    if (!pq.empty() && curr == pq.top())
                    {
                        res++;
                        pq.pop();
                    }
                }
                tmp = res;
                result += res;
            }
            else
            {
                result += tmp;
            }
        }
        cout << "#" << tc << " " << result << '\n';
    }

    return 0;
}
