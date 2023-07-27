#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    // freopen("in5.txt", "r", stdin);

    string str;
    cin >> str;

    unordered_map<char, int> m;

    for (int i = 0; i < str.size(); i++)
    {
        if (islower(str[i]))
            str[i] -= 32;
        m[str[i]]++;
    }

    string res;

    for (int i = 0; i < str.size(); i++)
    {
        if (find(res.begin(), res.end(), str[i]) != res.end()) // 중복된 문자열 발견
        {
            m[str[i]]--;
            continue;
        }
        else
        {
            for (int j = res.size() - 1; j >= 0; j--)
            {
                if (str[i] < res[j] && m[res[j]] != 1)
                {
                    m[res[j]]--;
                    res.pop_back();
                }
                else
                    break;
            }
        }
        res.push_back(str[i]);
    }
    cout << res << '\n';

    return 0;
}