#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
            cnt0++;
        if (str[i] == '1')
            cnt1++;
    }

    cnt0 /= 2;
    cnt1 /= 2;

    while (cnt1 != 0)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '1')
            {
                str.erase(i, 1);
                cnt1--;
                break;
            }
        }
    }

    while (cnt0 != 0)
    {
        for (int i = str.size(); i >= 0; i--)
        {
            if (str[i] == '0')
            {
                str.erase(i, 1);
                cnt0--;
                break;
            }
        }
    }

    cout << str;

    return 0;
}
