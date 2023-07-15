#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    string a;
    int sum = 0, res = 0;
    cin >> a;
    // '0': 48 ~ 57
    for (char x : a)
    {
        // if (x >= 48 && x <= 57)
        if (isdigit(x))
            res = res * 10 + (x - 48);
        else
        {
            sum += res;
            res = 0;
        }
    }
    cout << sum + res << '\n';
    return 0;
}
