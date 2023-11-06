#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        unordered_map<string, int> m;
        cin >> n;

        string str1, str2;
        for (int i = 0; i < n; i++)
        {
            cin >> str1 >> str2;
            m[str2]++;
        }

        int res = 1;

        for (auto v : m)
        {
            res *= (v.second + 1);
        }

        cout << res - 1 << '\n';
    }

    return 0;
}
