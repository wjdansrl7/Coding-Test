#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    long long a, b;
    cin >> a >> b;

    int n = 0;

    while (pow(2, n) < b)
    {
        n++;
    } // n = 4;

    // for (int i = a; i <= b; i++)
    // {
    //     if (i + b != pow(2, n))
    //     {
    //         continue;
    //     }

    // }

    long long start = 0, end = b - a + 1;

    while (start < end)
    {
        
    }
    

    return 0;
}
