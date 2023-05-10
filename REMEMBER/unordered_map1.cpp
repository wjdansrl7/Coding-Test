#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> hs;

int main()
{
    hs.insert(make_pair<string, int>("greec", 1));
    hs.insert(make_pair<string, int>("luna", 3));
    hs.insert(make_pair<string, int>("selly", 7));
    hs.insert(make_pair<string, int>("del", 5));
    hs.insert(make_pair<string, int>("suprem", 4));
    hs.insert(make_pair<string, int>("nord", 3));
    hs.insert(make_pair<string, int>("ding", 2));
    hs.insert(make_pair<string, int>("creek", 2));
    hs.insert(make_pair<string, int>("sua", 3));

    // element access with key
    cout << "element access" << endl;
    cout << hs["greec"] << endl;
    cout << hs["ding"] << endl;
    cout << hs["sua"] << endl;
    cout << hs["eeqq"] << endl;
    cout << endl;

    // add value with the same key
    cout << "insert with the same key" << endl;
    hs.insert(make_pair<string, int>("greec", 10));
    cout << hs["greec"] << endl; // 1
    cout << endl;

    // update key with new value
    cout << "insert with the same key" << endl;
    auto iter = hs.find("greec");
    if (iter != hs.end())
    {
        hs.erase("greec");
    }
    hs.insert(make_pair<string, int>("greec", 10));
    cout << hs["greec"] << endl; // 10
    cout << endl;

    // not ordered
    cout << "iterator in map" << endl;
    for (auto i = hs.begin(); i != hs.end(); i++)
    {
        cout << i->first << ", " << i->second << endl;
    }

    /*
※ key 들이 정렬되어 있지 않다.

    creek, 2
    del, 5
    ding, 2
    eeqq, 0
    greec, 1
    luna, 3
    nord, 3
    selly, 7
    sua, 3
    suprem, 4
    */
}
