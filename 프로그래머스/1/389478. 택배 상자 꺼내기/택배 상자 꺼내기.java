import java.util.*;
import java.io.*;

/**
* 꺼내려는 상자를 포함
*/
class Solution {
    public int solution(int n, int w, int num) {
        int m = 0;
        if(n % w != 0) {
            m = n / w + 1;
        } else {
            m = n / w;
        }
        
        int[][] arr = new int[m][w];
        
        int idx = 1;
        label: for(int i = 0; i < m; i++) {
            
            
            if((i & 1) == 0) {
                for(int j = 0; j < w; j++) {
                    arr[i][j] = idx++;
                    if(idx > n) break label;
                } 
            } else {
                for(int j = w - 1; j >= 0; j--) {
                    arr[i][j] = idx++;
                    if(idx > n) break label;
                }
            }
        }
        
        int col, row, count = 0;
        label: for(int i = 0; i < m; i++) {
            for(int j = 0; j < w; j++) {
                if(arr[i][j] == num) {
                    col = i;
                    row = j;
                    
                    while (col < m && arr[col][row] != 0) {
                        count++;
                        col++;
                        
                    }
                    
                    break label;
                }
            }
        }
        
        return count;
    }
}