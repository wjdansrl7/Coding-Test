/*
brute-force
sliding-window

sliding window 문제는 처음 풀어봤다. 전체 영역에서 해당하는 영역을 반복문을 통해서
합하는 방식이다.
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{

    string str;
    cin >> str;

    int aSize = 0, bSize = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a')
        {
            aSize++;
        }
        else
            bSize++;
    }

    long long maxSum = 0;
    long long result1 = 0, result2 = 0;
    long long sum = 0;

    for (int i = 0; i < str.size() - aSize; i++)
    {
        sum = 0;
        for (int j = i; j < aSize + i; j++)
        {
            if (str[j] == 'a')
                sum += 1;
        }

        if (maxSum < sum)
            maxSum = sum;
    }

    result1 = aSize - maxSum;

    maxSum = 0;
    for (int i = 0; i < str.size() - bSize; i++)
    {
        sum = 0;
        for (int j = i; j < bSize + i; j++)
        {
            if (str[j] == 'b')
                sum += 1;
        }

        if (maxSum < sum)
        {
            maxSum = sum;
        }
    }

    result2 = bSize - maxSum;

    if (result1 < result2)
        cout << result1 << '\n';
    else
        cout << result2 << '\n';

    return 0;
}
