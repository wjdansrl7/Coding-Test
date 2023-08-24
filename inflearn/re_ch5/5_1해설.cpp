#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int n, sum = 0, i;
    cin >> str >> n;
    for (i = 3; i < str.size(); i++)
    {
        if (str.substr(0, i) == str.substr(i, i))
        {
            for (char x : str.substr(0, i))
                sum += (x - 48);
            break;
        }
    }

    int res = sum * (n / i);
    int len = n % i;
    for (int i = 0; i < len; i++)
    {
        res += (str[i] - 48);
    }
    cout << res;

    return 0;
}
