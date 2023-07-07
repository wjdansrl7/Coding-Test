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

// 중복 순열
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

// 순열
void permutation(int depth)
{
    if (depth == r)
    {
        printArray(pArr);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            pArr[depth] = i;
            permutation(depth + 1);
            check[i] = false;
        }
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

int main(int argc, char const *argv[])
{
    // cout << "순열 (순서O, 중복X)" << '\n';
    // permutation(0);

    // cout << "중복 순열 (순서O, 중복O)" << '\n';
    // duplicatePermutation(0);

    cout << "조합 (순서X, 중복X)" << '\n';
    combination(0, 1);

    // cout << "조합 (순서X, 중복O) " << '\n';
    // duplicateCombination(0, 1);

    return 0;
}
