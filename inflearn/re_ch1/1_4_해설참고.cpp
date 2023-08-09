#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int Can[2][17];
vector<int> ch(17, 0);
int res = INT_MAX;

void dfs(int L, int s)
{
    if (L == n / 2)
    {
        vector<int> A;
        vector<int> B;

        for (int i = 0; i < n; i++)
        {
            if (ch[i] == 0)
            {
                A.push_back(i);
            }
            else
                B.push_back(i);
        }

        int sumA = 0, sumB = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sumA += Can[0][A[i]];
            sumB += Can[1][B[i]];
        }
        res = min(res, abs(sumA - sumB));
    }
    else
    {
        for (int i = s; i < n; i++)
        {
            ch[i] = 1;
            dfs(L + 1, i + 1);
            ch[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in5.txt", "r", stdin);

    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        Can[0][i] = a;
        Can[1][i] = b;
    }

    dfs(0, 0);

    cout << res;

    return 0;
}
