#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);

    // if (find(v.begin(), v.end(), 1) != v.end())
    // {
    // cout << "찾았다";
    // }

    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto it : v)
    {
        cout << it << " ";
    }

    return 0;
}
