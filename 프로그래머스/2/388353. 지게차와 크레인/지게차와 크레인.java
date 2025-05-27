import java.io.*;
import java.util.*;

class Solution {
    static class Node {
        int x, y;
        
        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    public int solution(String[] storage, String[] requests) {
        int N = storage.length;
        int M = storage[0].length();
        
        boolean[][] visited = new boolean[N][M];
        List<Node>[] nodes = new List[26];
        
        for(int i = 0; i < 26; i++) nodes[i] = new ArrayList<>();
        
        for(int i = 0; i < N; i++) {
            String str = storage[i];
            for(int j = 0; j < M; j++) {
                nodes[str.charAt(j) - 'A'].add(new Node(i, j));
            }
        }
        
        int res = N * M;
        for(int i = 0; i < requests.length; i++) {
            
            res -= solve(requests[i], nodes, visited, N, M);
            
        }
        
        return res;    
    }
    
    static int solve(String str, List<Node>[] nodes, boolean[][] visited, int N, int M) {
        
        int cnt = 0;
        char target = str.charAt(0);
        
        if(nodes[target - 'A'].size() == 0) return cnt;
        
        ArrayDeque<int[]> q;
        
        if(str.length() > 1) {
            
            for(Node node : nodes[target - 'A']) {
                if(visited[node.x][node.y]) continue;
                
                visited[node.x][node.y] = true;
                cnt++;
            }
            
            
        } else {
            
            List<Node> succ = new ArrayList<>();
            for(Node node : nodes[target - 'A']) {
                boolean[][] v = new boolean[N][M];
                
                if(visited[node.x][node.y]) continue;
                
                q = new ArrayDeque<>();
                 
                q.offer(new int[]{node.x, node.y});
                v[node.x][node.y] = true;
                
                while(!q.isEmpty()) {
                    
                    int[] p = q.poll();
                    
                    if(p[0] == 0 || p[0] == N - 1 || p[1] == 0 || p[1] == M - 1) {
                        succ.add(new Node(node.x, node.y));
                        cnt++;
                        break;
                    }
                    
                    for(int d = 0; d < 4; d++) {
                        int nx = p[0] + dx[d];
                        int ny = p[1] + dy[d];
                        
                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if(!visited[nx][ny] || v[nx][ny]) continue;
                        
                        q.offer(new int[]{nx, ny});
                        v[nx][ny] = true;
                    }
                }
            }
            
            for(Node node : succ) {
                visited[node.x][node.y] = true;
            }
        }
        
        return cnt;
    }
}