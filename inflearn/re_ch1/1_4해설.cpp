#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, res = 2147000000, can[2][21], ch[21];
void DFS(int L, int s)
{
    if (L == n / 2)
    {
        vector<int> A, B;
        for (int i = 0; i < n; i++)
        {
            if (ch[i])
                A.push_back(i);
            else
                B.push_back(i);
        }
        int sumA = 0, sumB = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sumA += can[0][A[i]];
            sumB += can[0][B[i]];
        }
        res = min(res, abs(sumA - sumB));
    }
    else
    {
        for (int i = s; i < n; i++)
        {
            ch[i] = 1;
            DFS(L + 1, s + 1);
            ch[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> can[0][i] >> can[1][i];
    }
    DFS(0, 0);
    cout << res;

    return 0;
}
