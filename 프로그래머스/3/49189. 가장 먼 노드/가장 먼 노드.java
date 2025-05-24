import java.util.*;
import java.io.*;

class Solution {
    public int solution(int n, int[][] edge) {
        int answer = 0;
        
        List<Integer>[] graph = new List[n+1];
        for(int i = 0; i < n+1; i++) graph[i] = new ArrayList<>();
        
        // 그래프간의 간선 연결
        int a, b;
        for(int i = 0; i < edge.length; i++) {
            a = edge[i][0];
            b = edge[i][1];
            
            graph[a].add(b);
            graph[b].add(a);
        }
        
        int[] dist = new int[n+1];
        Arrays.fill(dist, 50001);
        
        ArrayDeque<int[]> q = new ArrayDeque<>();
        
        q.offer(new int[]{1, 0});
        dist[1] = 0;
        
        while(!q.isEmpty()) {
            
            int[] p = q.poll();
            
            for(Integer next : graph[p[0]]) {
                if(dist[next] > p[1] + 1) {
                    q.offer(new int[]{next, p[1] + 1});
                    dist[next] = p[1] + 1;
                }   
            }   
        }
        
        int max = -1;
        
        for(int i = 1; i < n+1; i++) {
            if(dist[i] > max) max = dist[i];
        }
        
        for(int i = 1; i < n + 1; i++) {
            if(dist[i] == 50001) continue;
            if(max == dist[i]) answer++;
        }
        
        return answer;
    }
}