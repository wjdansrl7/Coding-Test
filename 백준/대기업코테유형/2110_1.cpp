#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<long long> v;

int recursive(int start, int end, int c)
{
    if (c == 0)
    {
        return 0;
    }

    int maxIdx = -1, maxLen = 0;
    for (int i = start + 1; i < end; i++)
    {
        if (maxLen < min(v[i] - v[start], v[end] - v[i]))
        {
            maxLen = min(v[i] - v[start], v[end] - v[i]);
            maxIdx = i;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> c;

    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    if (c == 2)
    {
        cout << v[n - 1] - v[0] << '\n';
        return 0;
    }

    recursive(0, n - 1, c - 2);

    return 0;
}
