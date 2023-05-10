#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

int number = 9999999;
int primeNum[10000000];

void Eratos(int maxNumber)
{
    for (int i = 2; i <= maxNumber; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(maxNumber); i++)
    {

        for (int j = i * i; j <= maxNumber; j += i)
        {
            if (primeNum[j] == 0)
                continue;

            primeNum[j] = 0;
        }
    }
}

int solution(string numbers)
{
    int answer = 0;
    string s;
    unordered_map<int, int> allNum;
    int maxNum;

    sort(numbers.begin(), numbers.end(), greater<>());
    maxNum = stoi(numbers);

    Eratos(maxNum);

    sort(numbers.begin(), numbers.end());

    do
    {
        for (int i = 1; i <= numbers.size(); i++)
        {
            string x = numbers.substr(0, i);
            allNum.insert({stoi(x), 1});
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    for (auto i : allNum)
    {
        if (primeNum[i.first] != 0)
            answer++;
    }
    return answer;
}