#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    int dest[5];
    // copy(begin(arr), end(arr), begin(dest));
    copy_n(arr, size, dest);

    for (auto &i : dest)
    {
        cout << i << " ";
    }

    return 0;
}
