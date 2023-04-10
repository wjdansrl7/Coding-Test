#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int rechange;

    cin >> rechange;

    int result = 1000 - rechange;

    int num = 0;

    if (result / 500)
    {
        num += result / 500;

        result -= 500 * (result / 500);
    }

    if (result / 100)
    {
        num += result / 100;

        result -= 100 * (result / 100);
    }

    if (result / 50)
    {
        num += result / 50;

        result -= 50 * (result / 50);
    }

    if (result / 10)
    {
        num += result / 10;

        result -= 10 * (result / 10);
    }

    if (result / 5)
    {
        num += result / 5;

        result -= 5 * (result / 5);
    }

    if (result / 1)
    {
        num += result / 1;

        result -= 1 * (result / 1);
    }

    cout << num << "\n";

    return 0;
}
