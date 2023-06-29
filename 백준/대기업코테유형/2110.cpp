#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
long long res;

void parametric_search(int n, int c)
{
    int start = 0, end = n - 1;

    if (c == 2)
    {
        res = v[end] - v[start];
        return;
    }
    else
    {
    }
}

int main(int argc, char const *argv[])
{
    int n, c;

    cin >> n >> c;

    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    parametric_search(n, c);

    return 0;
}
