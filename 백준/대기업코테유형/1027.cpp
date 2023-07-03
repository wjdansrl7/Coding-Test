#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    vector<pair<int, int>> v;
    stack<pair<int, int>> stk;
    vector<int> curve;
    cin >> n;

    long long h;
    for (int i = 1; i <= n; i++)
    {
        cin >> h;
        v.push_back({i, h});
    

    // 1,1 2,5 3,3 4,2 5,6 6,3 7,2 8,6 9,4 10,2 11,5 12,7 13,3 14,1 15,5

    stk.push({v[0].first, v[0].second});

    while (!stk.empty())
    {
        int curr_idx = stk.top().first;
        int curr_height = stk.top().second;
        
        for (int i = 1; i < v.size(); i++)
        {
            if (curr_height > v[i].second)
            {
                int t = (curr_height - v[i].second) / (v[i].first - curr_idx);

                curve.push_back()
            }
            
        }
        
    }
    
    
    return 0;
}
