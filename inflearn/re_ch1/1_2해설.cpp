#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t, s, res = 0;
    cin >> n >> m >> t >> s;
    vector<int> x, y;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            int cnt = 0;
            for (int k = 0; k < t; k++)
            {
                if (x[k] >= x[i] && x[k] <= x[i] + s)
                {
                    if (y[k] >= y[j] && y[k] <= y[j] + s)
                    {
                        cnt++;
                    }
                }
            }
            res = max(res, cnt);
        }
    }
    cout << res;

    return 0;
}
