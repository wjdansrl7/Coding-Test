#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string str = "abcdef";
    char arr[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++)
    {
        if (find(str.begin(), str.end(), arr[i]) != str.end())
        {
            cout << "ok" << '\n';
            break;
        }
    }

    return 0;
}
