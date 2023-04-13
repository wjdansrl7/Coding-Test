#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    set<pair<int, int>> a;

    a.insert({1, 2});
    a.insert({2, 3});
    a.insert({-1, 4});
    a.insert({-1, 5});
    a.insert({-1, -2});
    a.insert({4, 2});

    for (const auto &p : a)
    {
        cout << p.first << " " << p.second << '\n';
    }

    string s = '*';
    cout << s * 12 << '\n';
    return 0;
}
