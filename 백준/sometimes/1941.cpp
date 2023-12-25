#include <iostream>
#include <string>
using namespace std;

char pan[5][5];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void combination()
{
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    for (int i = 0; i < 5; i++)
    {
        cin >> str;
        for (int j = 0; j < 5; j++)
        {
            pan[i][j] = str[j];
        }
    }

    return 0;
}
