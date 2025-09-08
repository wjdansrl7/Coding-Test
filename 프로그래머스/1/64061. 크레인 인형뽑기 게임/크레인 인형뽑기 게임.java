import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        // 사라진 인형의 개수
        int answer = 0;
        
        ArrayDeque<Integer> stk = new ArrayDeque<>();
        
        for(int i = 0; i < moves.length; i++) {
            int row = moves[i] - 1;
            
            // 인형 뽑기
            for(int j = 0; j < board.length; j++) {
                int target = board[j][row];
                
                if(target != 0) {
                    if(!stk.isEmpty()) {
                        if(stk.peek() == target) {
                            answer += 2;
                            stk.pop();
                        } else {
                            stk.push(target);        
                        }
                    } else {
                        stk.push(target);    
                    }
                    
                    board[j][row] = 0;
                    break;
                }
            }
            
        }
        return answer;
    }
}