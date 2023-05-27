#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> triangle(3, 0);

    while (1)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> triangle[i];
        }

        sort(triangle.begin(), triangle.end());

        if (triangle[0] == triangle[1] && triangle[1] == triangle[2] && triangle[0] == 0)
        {
            break;
        }

        if (triangle[0] == triangle[1] && triangle[1] == triangle[2] && triangle[0] != 0)
        {
            cout << "Equilateral" << '\n';
            continue;
        }

        if (triangle[0] + triangle[1] > triangle[2])
        {
            if (triangle[0] == triangle[1] || triangle[1] == triangle[2])
            {
                cout << "Isosceles" << '\n';
                continue;
            }
            else
            {
                cout << "Scalene" << '\n';
                continue;
            }
        }
        else
        {
            cout << "Invalid" << '\n';
            continue;
        }
        return 0;
    }
}

// 나보다 더 간단한 풀이
// #include <cstdio>
// int main()
// {
//     int a, b, c;
//     while (1)
//     {
//         scanf("%d %d %d", &a, &b, &c);
//         if (!a)
//             break;
//         if (a >= b + c || b >= a + c || c >= a + b)
//             printf("Invalid\n");
//         else if (a == b && b == c)
//             printf("Equilateral\n");
//         else if (a == b || b == c || a == c)
//             printf("Isosceles\n");
//         else
//             printf("Scalene\n");
//     }
// }