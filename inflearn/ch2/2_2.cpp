#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("in5.txt", "r", stdin);

    string str, target;
    int alpha[26] = {
        0,
    };
    int res = 0;

    cin >> str >> target;

    for (int i = 0; i < target.size(); i++)
    {
        alpha[int(target[i]) - 'a']++;
    }

    for (int i = 0; i <= str.size() - target.size(); i++)
    {
        int cnt = 0;
        for (int j = i; j < target.size() + i; j++)
        {
            if (alpha[int(str[j]) - 'a'] != 0)
            {
                alpha[int(str[j]) - 'a']--;
                cnt++;
            }
            else
            {
                break;
            }
        }

        if (cnt == target.size())
        {
            res++;
        }

        memset(alpha, 0, sizeof(alpha));

        for (int j = 0; j < target.size(); j++)
        {
            alpha[int(target[j]) - 'a']++;
        }
    }

    cout << res << '\n';
}