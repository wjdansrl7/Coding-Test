#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    int n;
    cin >> n;

    string str, str2, res;

    cin >> str;
    for (int i = 1; i < n; i++)
    {
        cin >> str2;

        int minLen = min(str.size(), str2.size());

        for (int j = 0; j < minLen; j++)
        {
            if (str[j] == str2[j])
                res += str[j];
            else
                break;
        }
        str = res;
        res.clear();
    }

    cout << str << '\n';

    return 0;
}
