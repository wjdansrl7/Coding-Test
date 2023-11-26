#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "abcde";

    for (int i = 0; i < a.size(); i++)
    {
        a[i] = toupper(a[i]);
    }

    cout << a;

    return 0;
}
