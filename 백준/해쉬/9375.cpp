#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        unordered_map<string, int> cloth;

        cin >> n;

        string name, menu;

        for (int i = 0; i < n; i++)
        {
            cin >> name >> menu;
            cloth[menu]++;
        }

        int res = 1;

        for (auto v : cloth)
        {
            res *= v.second + 1;
        }

        cout << res - 1 << '\n';
    }

    return 0;
}
