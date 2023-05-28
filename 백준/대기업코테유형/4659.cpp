#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int alphabet[26] = {
        0,
    };
    string str, password;

    int arr[] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < 5; i++)
    {
        alphabet[arr[i] - 'a'] = 1;
    }

    while (1)
    {
        bool endflag = true;
        password = "";
        cin >> str;

        if (str == "end")
        {
            break;
        }

        for (int i = 0; i < str.size(); i++)
        {
            password += to_string(alphabet[str[i] - 'a']);
        }

        // cout << password << '\n';

        if (find(password.begin(), password.end(), '1') == password.end())
        {
            endflag = false;
            // 모음이 하나도 없음
        }

        int cnt_0 = 0, cnt_1 = 0;
        for (int i = 0; i < password.size(); i++)
        {
            if (password[i] == '0')
            {
                cnt_0++;
                cnt_1 = 0;
            }

            if (password[i] == '1')
            {
                cnt_1++;
                cnt_0 = 0;
            }

            if (cnt_0 == 3 || cnt_1 == 3)
            {
                endflag = false;
                break;
                // 모음 또는 자음이 3개가 연속으로 나온 것이다.
            }
        }

        for (int i = 0; i < str.size() - 1; i++)
        {
            if (str[i] == str[i + 1])
            {
                if (str[i] == 'e' || str[i] == 'o')
                {
                    continue;
                }
                else
                {
                    // 3번 위배
                    endflag = false;
                    break;
                }
            }
        }

        if (endflag)
        {
            cout << "<" << str << "> is acceptable." << '\n';
            continue;
        }
        else
        {
            cout << "<" << str << "> is not acceptable." << '\n';
            continue;
        }
    }

    return 0;
}
