#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    string result;
    bool visited[3][3];

    while (1)
    {
        int x = 0, o = 0;
        cin >> str;

        if (str == "end")
        {
            break;
        }

        int idx = 0;
        for (int i = 0; i < 9; i++)
        {
            visited[idx][i] = 
        }
        

        for (int i = 0; i < 9; i++)
        {
            if (str[i] == 'x')
            {
                x++;
            }
            else if (str[i] == 'o')
            {
                o++;
            }     
        }

        if (o < 3)
        {
            if (o == 2 && x - o == 1)
            {
            }
            else
            {
                result = "invalid";
            }

            
        }
        
        if (x < 3)
        {
            result = "invalid";
        }

        
        

        // x - o의 차가 1이 넘어가는 경우 invalid
        if (x - o > 1)
        {
            result = "invalid";
        }

        // x와 o를 합했을 때 모든 공간을 다 채우고, x - o == 1일 경우 valid
        if (x + o == 9 && x - o == 1) 
        {
            result = "valid";
        }
        
        
        


        
    }
        
    return 0;
}

