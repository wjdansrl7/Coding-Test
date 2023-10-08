#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string a = "Time is 2020Year 03Month";
    cout << a.size() << '\n';

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';

    for (int i = 0; i < a.size(); i++)
    {
        if (isupper(a[i]))
        {
            cout << a[i] << " ";
        }
    }
    cout << '\n';

    for (int i = 0; i < a.size(); i++)
    {
        if (islower(a[i]))
        {
            cout << a[i] << " ";
        }
    }
    cout << '\n';

    for (int i = 0; i < a.size(); i++)
    {
        if (isdigit(a[i]))
        {
            cout << a[i] << " ";
        }
    }
    cout << '\n';

    cout << a.find('Y') << '\n';

    a.push_back('s'); // a += 's;
    cout << a << '\n';

    a.pop_back();
    cout << a << '\n';

    a += " 27day";
    cout << a << '\n';

    cout << a.substr(8) << '\n';
    cout << a.substr(8, 4) << '\n';
    a.clear();

    cout << a << '\n';

    return 0;
}
