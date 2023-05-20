#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        string s, t;

        cin >> s >> t;

        int sSzie = s.size();
        int tSize = t.size();

        string tmp_s, tmp_t;

        for (int i = 0; i < tSize; i++)
        {
            tmp_s += s;
        }

        for (int i = 0; i < sSzie; i++)
        {
            tmp_t += t;
        }

        if (tmp_s == tmp_t)
        {
            cout << "#" << tc + 1 << " yes" << '\n';
        }
        else
            cout << "#" << tc + 1 << " no" << '\n';
    }

    return 0;
}
