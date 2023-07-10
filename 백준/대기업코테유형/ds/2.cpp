#include <iostream>
#include <cstring>
using namespace std;

int col[200005];
int n, m, q;
long long res;

void goMars()
{
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        int idx = 1;

        while (idx < i && flag)
        {
            if (col[i] == col[idx])
            {
                flag = false;
                break;
            }

            idx++;
        }

        if (flag)
        {
            res++;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        memset(col, 0, sizeof(col));
        res = 0;
        cin >> n >> m >> q;

        for (int i = 1; i <= n; i++)
        {
            long long cnt, maxCnt = -1;
            int maxIdx;
            for (int j = 1; j <= m; j++)
            {
                cin >> cnt;
                if (maxCnt < cnt)
                {
                    maxCnt = cnt;
                    maxIdx = j;
                }
            }
            col[i] = maxIdx;
        }

        int r, c;
        long long x;
        for (int i = 0; i < q; i++)
        {
            cin >> r >> c >> x;
            if (col[r] < x)
            {
                col[r] = c;
                goMars();
            }
        }

        cout << "#" << tc << " " << res << '\n';
    }

    return 0;
}
