#include <iostream>
#include <string>
using namespace std;

int n, m;
int power[100001];
string nickname[100001];

int binsearch(int p)
{
    int l = 0, r = n - 1;
    int res;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (power[mid] >= p)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return res;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> nickname[i] >> power[i];
    }

    int p;
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        cout << nickname[binsearch(p)] << '\n';
    }

    return 0;
}
