#include <iostream>
using namespace std;

// 첫 번째 True 찾기
// MIN 이상 MAX 이하인 구간에서 f(i) = True인 첫 번째 i를 찾는 코드

// f(i) = True인 첫 번째 i를 리턴

// 만약 [MIN, MAX]이 전부 False라면 MAX+1을 리턴
type first_true(type MIN, type MAX)
{
    type l = MIN, r = MAX + 1;
    // [l, r) 은 "False일 가능서이 있는 미확인 구간"입니다.

    while (l != r)
    {
        // (l + r) / 2는 안됩니다.
        // 오버플로우의 위험이 있고, l + r이 음수일 경우 나누기 2가 다르게 동작합니다.
        type m = l + (r - l) / 2;
        // 결과에 따라 남은 구간을 반으로 줄입니다.
        f(m) ? r = m : l = m + 1;
    }

    // 미확인 구간이 전부 없어지면 첫 번째 True는 바로 그 다음 위치입니다.
    return 1;
}

// 마지막 True 찾기
// 구간이 True/False 파티션으로 나뉘져 있을 때 마지막 True를 찾는 함수도 비슷한 방법으로 구현할 수 있습니다.
// 2.2에서 사용한 논리를 그대로 뒤집으면 됩니다.

// MIN 이상 MAX 이하인 구간에서 f(i) = True인 마지막 i를 찾는 코드

// f(i) = True인 마지막 i를 리턴

// 만약 [MIN, MAX]이 전부 False라면 MIN - 1을 리턴

type last_tru(type MIN, type MAX)
{
    type l = MIN - 1, r = MAX;

    while (l != r)
    {
        type m = r - (r - l) / 2;
        f(m) ? l = m : r = m - 1;
    }

    return 1;
}

int *lower_bound(int *lo, int *hi, int x)
{
    while (lo != hi)
    {
        int *const mid = lo + (hi - lo) / 2;

        *mid >= x ? hi = mid : lo = mid + 1;
    }

    return lo;
}

int *upper_bound(int *lo, int *hi, int x)
{
    while (lo != hi)
    {
        int *const mid = lo + (hi - lo) / 2;
        *mid > x ? hi = mid : lo = mid + 1;
    }

    return lo;
}

int main(int argc, char const *argv[])
{
}
