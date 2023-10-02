/*
문제의 아이디어를 잡지 못해 아쉬웠다.
문제는 string을 완탐을 통해서 해결하는 문제이다.
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int j = 0;
    int res;
    for (int i = 1; i < 100000; i++)
    {
        string sNum = to_string(i);
        for (auto s : sNum)
        {
            if (str[j] == s)
            {
                j++;
            }
        }

        if (j == str.size())
        {
            res = i;
            break;
        }
    }

    cout << res;

    return 0;
}
