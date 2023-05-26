#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    map<char, int> m;

    int t = 2;
    for (int i = 0; i < 15; i++)
    {
        char a = char('A' + i);
        if (i % 3 == 0 && i != 0)
            t++;

        m.insert({a, t});
    }
    for (int i = 0; i < 4; i++)
    {
        char a = char('P' + i);
        m.insert({a, 7});
    }

    for (int i = 0; i < 3; i++)
    {
        char a = char('T' + i);
        m.insert({a, 8});
    }
    for (int i = 0; i < 4; i++)
    {
        char a = char('W' + i);
        m.insert({a, 9});
    }

    cin >> str;
    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        sum += m[str[i]];
    }

    cout << sum + str.size() << '\n';

    char a = 'A';
    cout << (int)a - 65;

    // ABC DEF GHI JKL MNO PQRS TUV WXYZ

    return 0;
}
