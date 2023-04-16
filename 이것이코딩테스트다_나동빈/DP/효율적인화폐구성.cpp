#include <iostream>
#include <cstring>

using namespace std;

int d[10000];

int main(int argc, char const *argv[])
{
    int money, n;
    memset(d, 10001, sizeof(d));

    cin >> n >> money;

    d[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        d[a] = 1;
    }

    for (int i = 0; i < money; i++)
    {
        
    }
    
    
    return 0;
}
