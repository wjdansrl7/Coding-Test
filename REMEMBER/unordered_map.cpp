#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<string, int> um;

    if (um.empty())
    {
        cout << "unoredered_map empty" << '\n';
    }

    um.insert(make_pair("key", 1));
    um["banana"] = 2;
    um.insert({"melon", 3});

    cout << "Size: " << um.size() << '\n';

    // auto로 해도 무방
    for (pair<string, int> elem : um)
    {
        cout << "key : " << elem.first << " " << elem.second << '\n';
    }

    if (um.find("banana") != um.end())
    {
        um.erase("banana");
    }

    cout << um.size() << '\n';

    for (auto elem : um)
    {
        cout << "key : " << elem.first << " " << elem.second << '\n';
    }
    return 0;
}
