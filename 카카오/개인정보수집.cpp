#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;

    unordered_map<string, int> t;

    string t_year = today.substr(0, 4);
    string t_month = today.substr(5, 2);
    string t_day = today.substr(8, 2);

    for (int i = 0; i < terms.size(); i++)
    {
        t[terms[i].substr(0, 1)] = stoi(terms[i].substr(2, 1));
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        string p_year = privacies[i].substr(0, 4);
        string p_month = privacies[i].substr(5, 2);
        string p_day = privacies[i].substr(8, 2);

        int pp_month = stoi(p_month) + t[privacies[i].substr(11, 1)];

        if (pp_month > 12)
        {

            p_year = to_string(stoi(p_year) + pp_month / 12);
            p_month = to_string(pp_month % 12);
        }
        else
        {
            p_month = to_string(pp_month);
        }

        if (stoi(t_day) >= stoi(p_year))
        {
            if (stoi(t_month) >= stoi(p_month))
            {
                if (stoi(t_day >= p_day))
                {
                    answer.push_back(i + 1);
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
