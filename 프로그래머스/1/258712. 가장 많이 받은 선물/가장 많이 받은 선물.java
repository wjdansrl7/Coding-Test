import java.util.*;
import java.io.*;

/**
* 선물을 주고 받은 기억이 있는 경우, 더 많이 준 사람이 다음달에 받는다.
* 주고 받지 않았다면 선물 지수를 통해 선물을 받는다.
* 만약 서로 준 횟수가 동일한 경우, 선물지수가 더 큰 사람이 선물을 받느다.

* 가장 많이 받는 친구의 선물의 개수를 출력한다.
*/

class Solution {
    public int solution(String[] friends, String[] gifts) {
        
        int N = friends.length;
        Map<String, Integer> map = new HashMap<>();
        int[][] arr = new int[N][N];
        
        for(int i = 0; i < N; i++) {
            map.put(friends[i], i);
        }
        
        int A, B;
        for(int i = 0; i < gifts.length; i++) {
            
            A = map.get(gifts[i].split(" ")[0]);
            B = map.get(gifts[i].split(" ")[1]);
            
            arr[A][B]++;
        }
        
        int[] points = new int[N];
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                points[i] += arr[i][j];
                points[j] -= arr[i][j];
            }
        }
        
        int[] res = new int[N];
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(arr[i][j] > arr[j][i]) res[i]++;
                else if(arr[i][j] < arr[j][i]) res[j]++;
                else {
                    if(points[i] > points[j]) res[i]++;
                    else if(points[i] < points[j]) res[j]++;
                }       
            }
        }
        
        int max = 0;
        
        for(int i = 0; i < N; i++) if(max < res[i]) max = res[i];
        
        return max;
    }
}