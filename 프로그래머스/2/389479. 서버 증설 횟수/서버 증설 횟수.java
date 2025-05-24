import java.util.*;
import java.io.*;

/**
* m: 서버 한대당 가용 가능한 인원
* k: 서버 한대당 유지 가능한 시간
*/

class Solution {
    public int solution(int[] players, int m, int k) {
        int result = 0;
        int server = 0; // 기본적으로 한대만 돌아가고 있음
        List<Integer> ttl = new ArrayList<>();
        
        for(int i = 0; i < players.length; i++) {
            
            while (!ttl.isEmpty() && ttl.get(0) == i) {
                // 서버 운영 가능시간 확인
                ttl.remove(0);
                server--;
            }
            
            if (players[i] >= (server + 1) * m) {
                // 서버가 더 필요한 경우
                int cnt = players[i] / m - server;
                // 증설 횟수
                result += cnt;
                
                for(int j = 0; j < cnt; j++) {
                    server++;
                    ttl.add(i + k);
                }
            }            
        }
        
        return result;
    }
}