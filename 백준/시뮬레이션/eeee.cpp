#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[11][11] = {
        0,
    };

    cout << sizeof(arr) / sizeof(int) << '\n';
    return 0;
}
