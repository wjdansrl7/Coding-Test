#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int power[100001];
string nickname[100001];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> nickname[i] >> power[i];

    int p;
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        int idx = lower_bound(power, power + n, p) - power;
        cout << nickname[idx] << '\n';
    }

    return 0;
}
