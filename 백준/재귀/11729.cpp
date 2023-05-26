#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int bypass)
{
    if (n == 1)
    {
        cout << from << " " << to << '\n';
        return;
    }

    hanoi(n - 1, from, bypass, to);
    cout << from << " " << to << '\n';
    hanoi(n - 1, bypass, to, from);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    hanoi(n, 1, 3, 2);
    return 0;
}
