#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<long long> water;
long long res1, res2;

void search(int n)
{
    int start = 0, end = n - 1;
    long long minResult = 3e9;

    while (start < end)
    {
        if (abs(water[start] + water[end]) < minResult)
        {
            res1 = water[start];
            res2 = water[end];
            minResult = abs(water[start] + water[end]);
        }

        if (water[start] + water[end] >= 0)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        water.push_back(x);
    }

    sort(water.begin(), water.end());

    search(n);

    cout << res1 << " " << res2 << '\n';

    return 0;
}
