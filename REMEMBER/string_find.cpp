#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string str = "hello, world";
    size_t pos = str.find("world");
    if (pos != string::npos)
    {
        cout << "found" << pos << '\n';
    }
    else
    {
        cout << "not found" << '\n';
    }

    std::vector<int> vec = {1, 2, 3, 42, 5};
    auto iter = find(vec.begin(), vec.end(), 42);
    if (iter != vec.end())
    {
        std::cout << "Found at position " << std::distance(vec.begin(), iter) << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}
