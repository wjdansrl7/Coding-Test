#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int n;
    long long res = 0;
    vector<int> v;
    while (T--)
    {
        v.clear();
        res = 0;
        cin >> n;

        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }

        int MAX = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            MAX = max(MAX, v[i]);
            res += MAX - v[i];
        }

        cout << res << '\n';
    }

    return 0;
}
