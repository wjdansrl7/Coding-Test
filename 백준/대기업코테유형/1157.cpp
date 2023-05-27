#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[26] = {
        0,
    };
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 97)
        {
            arr[(int)str[i] - 97]++;
        }
        else
        {
            arr[(int)str[i] - 65]++;
        }
    }

    int idx, maxCnt = 0;
    int cnt = 0;

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > maxCnt)
        {
            maxCnt = arr[i];
            idx = i;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (maxCnt == arr[i])
        {
            cnt++;
        }
    }

    if (cnt > 1)
    {
        cout << "?" << '\n';
    }
    else
    {
        cout << char(idx + 65) << '\n';
    }

    return 0;
}
