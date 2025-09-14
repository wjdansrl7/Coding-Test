import java.util.*;
import java.io.*;


class Solution {
    public String[] solution(String[] record) {
        
        int N = record.length; // <= 100,000        
        Map<String, String> map = new HashMap<>();
        int len = N;
        
        for(int i = 0; i < N; i++) {
            
            String[] str = record[i].split(" ");
            
            if(str[0].equals("Change")) {
                len--;
            }
            
            if(str[0].equals("Enter") || str[0].equals("Change")) {
                // 닉네임 변경
                map.put(str[1], str[2]);
            }
        }
        
        String[] answer = new String[len];
        Arrays.fill(answer, "");

        int idx = 0;
        for(int i = 0; i < N; i++) {
            
            String type = record[i].split(" ")[0];
            String id = record[i].split(" ")[1];
            
            if(type.equals("Enter")) {
                answer[idx] = answer[idx].concat(map.get(id)).concat("님이 들어왔습니다.");
                idx++;
            } else if(type.equals("Leave")) {
                answer[idx] = answer[idx].concat(map.get(id)).concat("님이 나갔습니다.");
                idx++;
            }
        }
        
        return answer;
    }
}