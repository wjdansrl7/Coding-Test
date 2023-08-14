#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 중복을 제거하는 목적
int main(int argc, char const *argv[])
{
    vector<int> a = {1, 3, 2, 3, 2, 3, 2, 3, 1, 2};
    set<int> s;
    multiset<int> s2;

    for (int i = 0; i < a.size(); i++)
    {
        s.insert(a[i]);
        s2.insert(a[i]);
    }

    cout << s.size() << '\n';
    cout << s2.size() << '\n';

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << '\n';

    for (auto it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << '\n';

    for (auto x : s)
        cout << x << " ";

    if (s.find(4) == s.end())
    {
        cout << "false" << '\n';
    }
    else
    {
        cout << "true" << '\n';
    }

    return 0;
}
