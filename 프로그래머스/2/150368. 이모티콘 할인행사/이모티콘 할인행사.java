import java.util.*;
class Solution {
    static class emoticonPlus implements Comparable<emoticonPlus> {
        int plus;
        int total;
        
        public emoticonPlus(int plus, int total) {
            this.plus = plus;
            this.total = total;
        }
        
        @Override
        public int compareTo(emoticonPlus e1) {
            if(this.plus == e1.plus) return Integer.compare(e1.total, this.total);
            return Integer.compare(e1.plus, this.plus);
        }
    }
    static int[] v = new int[8];
    
    static void permutation(int n, int k, int[][] users, int[] emoticons) {
        if(n == k) {
            solve(v, users, emoticons);
            return;
        }
        
        for(int i = 1; i <= 4; i++) {
            if(v[k] != 0) continue;
            v[k] = i * 10;
            permutation(n, k+1, users, emoticons);
            v[k] = 0;
        }
    }
    
    static PriorityQueue<emoticonPlus> pq = new PriorityQueue<>();
    static void solve(int[] visited, int[][] users, int[] emoticons) {
        int plus = 0;
        int total = 0;
        
        for(int i = 0; i < users.length; i++) {
            int sum = 0;
            for(int j =0 ; j < visited.length; j++) {
                if(visited[j] >= users[i][0]) {
                    sum += (100 - visited[j]) * 0.01 * emoticons[j];
                    if(sum < users[i][1]) continue;
                    else {
                        plus++;
                        sum = 0;
                        break;
                    }
                }
            }
            if(sum < users[i][1]) total += sum;
        }
        pq.offer(new emoticonPlus(plus, total));
    }
    public int[] solution(int[][] users, int[] emoticons) {
        permutation(emoticons.length, 0, users, emoticons);
        
        emoticonPlus ee = pq.poll();
        int[] answer = new int[2];
        answer[0] = ee.plus;
        answer[1] = ee.total;
        return answer;
    }
}