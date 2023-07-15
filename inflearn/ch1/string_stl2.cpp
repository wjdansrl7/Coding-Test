#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string a = "it is time to study", res;

    int pos, max = INT_MIN;
    while ((pos = a.find(' ')) != string::npos)
    {
        string tmp = a.substr(0, pos);
        int len = tmp.size();
        if (len > max)
        {
            max = len;
            res = tmp;
        }

        cout << tmp << '\n';
        a = a.substr(pos + 1);
    }
    if (a.size() > max)
    {
        max = a.size();
        res = a;
    }

    cout << res << '\n';

    return 0;
}
