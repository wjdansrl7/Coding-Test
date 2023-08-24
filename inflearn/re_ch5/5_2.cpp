#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);
    string str, res;
    cin >> str;

    while (str.find(')') != string::npos)
    {
        int st = str.find('(');
        int et = str.find(')');

        int n = 0;
        for (int i = 0; i < st; i++)
        {
            n = n * 10 + int(str[i] - 48);
        }
        if (n == 0)
        {
            n = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = st + 1; j < et; j++)
            {
                res += str[j];
            }
        }
        str = str.substr(et + 1);
    }
    cout << res;

    return 0;
}
