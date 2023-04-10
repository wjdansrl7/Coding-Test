#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<pair<int, int>> q;

    q.push_back({1, 2});
    q.push_back({1, 3});
    q.push_back({1, 4});
    q.push_back({1, 5});
    q.push_back({1, 6});

    q.pop_back();

    cout << q.front().second;
    return 0;
}
