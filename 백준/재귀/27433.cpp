#include <iostream>

using namespace std;

long long factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    cout << factorial(N) << '\n';

    return 0;
}
