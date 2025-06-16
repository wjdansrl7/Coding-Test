import java.util.*;
import java.io.*;

class Solution {
    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,1,0,-1};
    public int solution(String[][] board, int h, int w) {
        
        int answer = 0;
        
        String target = board[h][w];
        
        for(int d = 0; d < 4; d++) {
            int nx = h + dx[d];
            int ny = w + dy[d];
            
            if(nx < 0 || nx >= board.length || ny < 0 || ny >= board[0].length) continue;
            
            if(target.equals(board[nx][ny])) {
                answer++;
            }
        }
        
        return answer;
    }
}