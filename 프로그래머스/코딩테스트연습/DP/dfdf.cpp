#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> vec(8);

    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < 10; i++)
    {
        vec[0].push_back(i);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << vec[0][i] << " ";
    }

    return 0;
}
