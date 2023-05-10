#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    string numbers = "011";
    int x = 0;

    sort(numbers.begin(), numbers.end());

    do
    {
        for (int i = 1; i <= numbers.size(); i++)
        {
            x = stoi(numbers.substr(0, i));
            printf("%d\n", x);
        }

    } while (next_permutation(numbers.begin(), numbers.end()));

    return 0;
}
