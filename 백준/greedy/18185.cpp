// 라면 사기(Small)

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int ramenFactory[10001];

    memset(ramenFactory, 0, sizeof(ramenFactory));

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> ramenFactory[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        if (ramenFactory[i+1] > ramenFactory[i+2])
        {
            
        }
        

    }
    
    
    
    


    return 0;
}
