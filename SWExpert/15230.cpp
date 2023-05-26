#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        string s;
        cin >> s;

        int cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
            {
                cnt++;
                for (int j = i + 1; j < s.size(); j++)
                {
                    if (s[j] == s[i] + 1)
                    {
                        cnt++;
                        s[i] = s[j];
                    }
                    else
                        break;
                }
            }
            break;
        }

        cout << "#" << tc + 1 << " " << cnt << '\n';
    }

    return 0;
}
