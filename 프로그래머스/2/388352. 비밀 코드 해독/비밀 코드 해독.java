import java.util.*;
import java.io.*;

/**
* 
*/

class Solution {
    static void combination(int cnt, TreeSet<Integer> lists, int n, int[][] q, int[] ans) {
        
        if(cnt == 5) {
            if(solve(lists, q, ans)) {
                result++;
            }
            
            return;
        }
        
        int start = lists.size() > 0 ? lists.last() + 1 : 1;
        for(int i = start; i <= n; i++) {
            
            lists.add(i);
            combination(cnt+1, lists, n, q, ans);
            lists.pollLast();
        }
        
        
    }
    
    static boolean solve(TreeSet<Integer> lists, int[][] q, int[] ans) {
        
        for(int i = 0; i < q.length; i++) {
            int cnt = 0;
            for(int j = 0; j < 5; j++) {
                if(lists.contains(q[i][j])) {
                    cnt++;
                }
                
            }
            
            if(cnt != ans[i]) {
                return false;
            }
            
        }
        
        return true;
    }
    
    static int result = 0;
    public int solution(int n, int[][] q, int[] ans) {
        
        TreeSet<Integer> lists = new TreeSet<>();
        combination(0, lists, n, q, ans);
        
        return result;
        
    }
}