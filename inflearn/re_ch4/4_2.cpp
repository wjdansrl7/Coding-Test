#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);

    string str, ans;
    cin >> str;
    unordered_map<char, int> m;

    for (int i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
        m[str[i]]++;
    }

    ans += str[0];
    m[str[0]]--;
    for (int i = 1; i < str.size(); i++)
    {
        if (ans.find(str[i]) == string::npos)
        {
            for (int j = ans.size() - 1; j >= 0; j--)
            {
                if (ans[j] > str[i] && m[ans[j]] > 0)
                {
                    ans.pop_back();
                }
                else
                    break;
            }
            ans += str[i];
        }
        m[str[i]]--;
    }
    cout << ans;

    return 0;
}
