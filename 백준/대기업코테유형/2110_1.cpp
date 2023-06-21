#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<long long> v;

void recursive(int start, int end, int c)
{
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

    return 0;
}
