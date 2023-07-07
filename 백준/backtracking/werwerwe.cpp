#include <iostream>
#define n 4
#define r 3
using namespace std;

int dcArr[r] = {
    0,
};

int cArr[r] = {
    0,
};
int dpArr[r] = {
    0,
};
int pArr[r] = {
    0,
};
bool check[n + 1] = {
    false,
};

void printArray(int arr[r])
{
    for (int i = 0; i < r; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

// 순열(순서 O, 중복X)
void permutation(int depth)
{
    if (depth == r)
    {
        printArray(pArr);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            pArr[depth] = i;
            permutation(depth + 1);
            visited[i] = false;
        }
    }
}

// 중복 순열(순서O, 중복O)
void duplicatePermutation(int depth)
{
    if (depth == r)
    {
        printArray(dpArr);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        dpArr[depth] = i;
        duplicatePermutation(depth + 1);
    }
}

// 조합
void combination(int depth, int next)
{
    if (depth == r)
    {
        printArray(cArr);
        return;
    }

    for (int i = next; i <= n; i++)
    {
        cArr[depth] = i;
        combination(depth + 1, i + 1);
    }
}

// 중복 조합
void duplicateCombination(int depth, int next)
{
    if (depth == r)
    {
        printArray(dcArr);
        return;
    }

    for (int i = next; i <= n; i++)
    {
        dcArr[depth] = i;
        duplicateCombination(depth + 1, i);
    }
}