#include <iostream>
#include <unordered_map>
using namespace std;

long long n, p, q;
long long res = 0;
unordered_map<long long, long long> m;

long long solution(long long x)
{
    if (x == 0)
        return 1;

    if (m[x] != 0)
    {
        return m[x];
    }
    else
    {
        return m[x] = solution(x / p) + solution(x / q);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p >> q;

    m[0] = 1;
    cout << solution(n);

    return 0;
}
