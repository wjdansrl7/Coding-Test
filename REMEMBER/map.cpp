#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{

    map<string, int> a;

    a.insert(make_pair("kim", 23));
    a.insert(make_pair("Jeong", 23));
    a.insert(make_pair("Yoon", 23));
    a.insert(make_pair("Hong", 23));
    a.insert(make_pair("kim", 23));

    for (auto m : a)
    {
        cout << m.first << m.second << '\n';
    }

    cout << a["kin"] << '\n';
    return 0;
}
