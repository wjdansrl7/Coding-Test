#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    string number = "17";
    int x = 0;

    sort(number.begin(), number.end());

    do
    {
        for (int i = 1; i <= number.size(); i++)
        {
            x = stoi(number.substr(0, i));
            printf("%d\n", x);
        }

    } while (next_permutation(number.begin(), number.end()));

    return 0;
}
