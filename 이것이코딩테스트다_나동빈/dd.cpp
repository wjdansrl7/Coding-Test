#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    int d[100];

    std::fill_n(d, 100, -2);
    // memset(d, -1, sizeof(d));

    for (int i = 0; i < 100; i++)
    {
        cout << d[i] << " ";
    }

    return 0;
}
