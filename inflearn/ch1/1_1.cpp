#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string str, result = "";

    while (n--)
    {
        cin >> str;

        if (result == "")
        {
            result = str;
            continue;
        }

        int minLen;

        if (result.size() < str.size())
        {
            minLen = result.size();
        }
        else
            minLen = str.size();

        string tmp = "";
        for (int i = 0; i < minLen; i++)
        {
            if (result[i] == str[i])
            {
                tmp += result[i];
            }
        }

        result = tmp;
    }

    cout << result << '\n';

    return 0;
}
