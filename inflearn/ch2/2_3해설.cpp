#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    freopen("in2.txt", "r", stdin);

    long long n, k;
    cin >> n;
    vector<long long> T(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> T[i];
    cin >> k;
    vector<long long> sT(T); // T vector를 복사
    sort(sT.begin(), sT.end());
    long long rest = n;
    for (int i = 1; i <= n; i++)
    {
        if (k < (rest * (sT[i] - sT[i - 1])))
        {
            int index = k % rest;
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (T[j] >= sT[i])
                {
                    if (cnt == index)
                    {
                        cout << j;
                        return 0;
                    }
                    cnt++;
                }
            }
        }
        else
        {
            k -= (rest * (sT[i] - sT[i - 1]));
            rest--;
        }
    }
    cout << "-1";
    return 0;
}
