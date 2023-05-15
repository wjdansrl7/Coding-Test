/*
해시 > 베스트앨범
map의 key를 이용하는 문제였다. 내가 아직 map STL을 자유자재로 사용하지 못해서
문제를 풀지 못했던 것 같다.
*/


#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> music;
    map<string, map<int, int>> musiclist;
    
    for(int i = 0; i < genres.size(); i++)
    {
        music[genres[i]] += plays[i];
        musiclist[genres[i]][i] = plays[i];
    }
    
    
    while(music.size() > 0)
    {
        int max = 0;
        string genre;
        for (auto m : music)
        {
            if (max < m.second)
            {
                max = m.second;
                genre = m.first;
            }
        }
        
        for(int i = 0; i < 2; i++)
        {
            int val = 0, ind = -1;
            for(auto ml : musiclist[genre])
            {
                if(val < ml.second)
                {
                    val = ml.second;
                    ind = ml.first;
                }
            }
            if (ind == -1) break;
            
            answer.push_back(ind);
            musiclist[genre].erase(ind);
        }
        music.erase(genre);
    }
    return answer;
}