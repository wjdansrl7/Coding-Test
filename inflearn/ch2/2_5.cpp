#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, d, k;
int res = INT_MIN;

void dfs(int L, int s, int bit, vector<int> &st, vector<int> &pow)
{
    if (L == k)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if ((st[i] & bit) == st[i])
            {
                cnt++;
            }
        }
        if (res < cnt)
        {
            res = cnt;
        }
    }
    else
    {
        for (int i = s; i <= d; i++)
        {
            dfs(L + 1, i + 1, bit + pow[i], st, pow);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);

    freopen("in5.txt", "r", stdin);

    cin >> n >> d >> k;

    vector<int> st(n + 1, 0), pow(d + 1, 0);

    pow[1] = 1;
    for (int i = 2; i <= d; i++)
    {
        pow[i] = pow[i - 1] * 2;
    }

    // 모든 학생들에 대해 비트 연산을 하기 위해
    // 음식의 번호에 대해서 이진수로 바꿔서 합했다.
    int m, num;
    for (int i = 0; i < n; i++)
    {
        cin >> m;

        for (int j = 0; j < m; j++)
        {
            cin >> num;
            st[i] += pow[num];
        }
    }

    dfs(0, 1, 0, st, pow);
    cout << res << '\n';

    return 0;
}
