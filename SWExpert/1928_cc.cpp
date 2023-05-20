#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input (20).txt", "r", stdin);
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        string s;
        cin >> s;

        string temp = "";

        cout << "#" << tc + 1 << " ";
        for (int i = 0; i <= s.size(); i++)
        {
            if (i > 0 && i % 4 == 0)
            {
                for (int j = 0; j < temp.size(); j += 8)
                {
                    int idx = 7;
                    int tmp = 0;
                    for (int t = 0; t <= 7; t++)
                    {
                        if (temp[j + t] == '1')
                        {
                            tmp += 1 << idx;
                        }
                        idx--;
                    }
                    cout << (char)tmp;
                }
                temp = "";
            }

            if (i == s.size())
            {
                continue;
            }

            int val = 0;
            if (s[i] == '+')
            {
                val = 62;
            }
            else if (s[i] == '/')
            {
                val = 63;
            }
            else
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    val = s[i] + 4;
                }
                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    val = s[i] - 65;
                }
                if (s[i] >= 'a' && s[i] <= 'z')
                {
                    val = s[i] - 97 + 26;
                }
            }

            for (int j = 5; j >= 0; j--)
            {
                if (val & (1 << j))
                {
                    temp += "1";
                }
                else
                    temp += "0";
            }
        }
        cout << '\n';
    }

    return 0;
}
