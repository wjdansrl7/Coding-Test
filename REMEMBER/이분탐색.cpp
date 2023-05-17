#include <iostream>
#include <vector>

using namespace std;

// 반복문을 사용했을 때
bool binary_search(vector<int> &arr, int len, int target)
{
    int low = 0, high = len - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (target == arr[mid])
            return true;

        if (target < arr[mid])
            high = mid - 1;
        else if (target > arr[mid])
            low = mid + 1;
    }

    return false;
}

bool binary_search(vector<int> &arr, int low, int high, int target)
{
    if (low > end)
        return false;

    if (arr[mid] == target)
        return true;

    if (arr[mid] > target)
        return binary_search(arr, low, mid - 1, target);
    else
        return binary_search(arr, mid + 1, high, target);
}

bin