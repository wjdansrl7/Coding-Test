#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    if (n & 1)
        cout << "SK" << '\n';
    else
        cout << "CY" << '\n';

    return 0;
}
