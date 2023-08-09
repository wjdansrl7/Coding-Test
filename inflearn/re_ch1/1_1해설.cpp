#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    freopen("in5.txt", "r", stdin);
    int n, len = INT_MAX;
    string str;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        words.push_back(str);

        // len = min(len, str.size());
        if (len > str.size())
        {
            len = str.size();
        }
    }

    // string res = "";
    // for (int i = 0; i < len; i++)
    // {
    //     set<char> tmp;
    //     // string tmp = "";
    //     for (auto &s : words)
    //     {
    //         // tmp += s[i];
    //         tmp.insert(s[i]); // 모든 string[i]의 값이 같다면 set의 크기는 1일 것이다(중복을 허용하지 않으므로)
    //     }
    // int m = count(tmp.begin(), tmp.end(), tmp[0]);
    // if (m == n)
    //     res += tmp[0];
    // else
    //     break;

    //     if (tmp.size() == 1)
    //         res += words[0][i];
    //     else
    //         break;
    // }

    string res = words[0];
    for (int i = 0; i < words.size(); i++)
    {
        while (words[i].find(res) != 0)
        {        
            res = res.substr(0, res.siz() - 1);
        }
    }

    cout << res;

    return 0;
}
