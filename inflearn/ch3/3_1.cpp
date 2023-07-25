#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    int n;
    char alpha;
    string str;

    cin >> n >> alpha;

    if (islower(alpha))
    {
        alpha -= 32;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> str;

        for (int j = 0; j < str.size(); j++)
        {
            if (islower(str[j]))
            {
                str[j] -= 32;
            }
        }

        string res;
        int cnt[26] = {
            0,
        };
        if (find(str.begin(), str.end(), alpha) != str.end())
        {
            for (int i = 0; i < str.size(); i++)
            {
                if (cnt[str[i] - 65] == 0)
                {
                    res += str[i];
                    cnt[str[i] - 65]++;
                }
            }
        }

        if (res != "")
        {
            cout << res << '\n';
        }
    }

    return 0;
}
