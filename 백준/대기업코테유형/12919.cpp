#include <iostream>
#include <string>
using namespace std;

string s, t;
int result;

void game(string s, string t)
{
    if (t.size() == s.size())
    {
        if (t == s)
        {
            result = 1;
            return;
        }
        return;
    }

    string tmp = "";
    // t의 문자열 뒤가 A인 경우 : A를 제거
    if (t[t.size() - 1] == 'A')
    {
        for (int i = 0; i < t.size() - 1; i++)
        {
            tmp += t[i];
        }
        game(s, tmp);
    }

    // t의 문자열 앞이 B인 경우 : 문자열을 뒤집고 B를 제거
    string tmp2 = "";
    if (t[0] == 'B')
    {
        for (int i = t.size() - 1; i > 0; i--)
        {
            tmp2 += t[i];
        }
        game(s, tmp2);
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    result = 0;
    cin >> s;
    cin >> t;

    game(s, t);

    cout << result << '\n';

    return 0;
}
