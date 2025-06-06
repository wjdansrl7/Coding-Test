import java.util.*;
import java.io.*;

/**
* 1. 초침, 분침, 시침에 각도를 구해준다.
* 2. 1초가 지난 후
* 2.1 1초가 지나기 전 hDegree > sDegree, 1초가 지난 후, hDegree < sDegree
* 2.2 1초가 지나기 전 mDegree > sDegree, 1초가 지난 후, mDegree < sDegree
* 1초가 지난 시점에 분침과 시침 모두 겹쳐진 경우, 중복이므로 하나로만 카운팅을 계산한다. validate

* 시각이 변화하는 각도 : 1시간 -> 30도, 분당 0.5도 초당 1/120도
* 분침이 변화하는 각도 : 분당 -> 6도, 초당 0.1도
* 시침이 변화하는 각도 : 초당 -> 6도 
*/
class Solution {
    static double hDegree, mDegree, sDegree;
    public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        int count = 0;
              
        // 초기 시각의 각도
        calculateDegree(h1, m1, s1);
        
        // 시작 시간과 종료 시간을 초로 변환
        int start = h1 * 3600 + m1 * 60 + s1;
        int end = h2 * 3600 + m2 * 60 + s2;
        
        if(Double.compare(hDegree, mDegree) == 0 || Double.compare(mDegree, sDegree) == 0) count++;
        
        
        // 시작 시간과 종료 시간이 동일해질 때, 종료
        while(start < end) {
            
            start++;
            count += timePast();
            
        }
        
        calculateDegree(h2, m2, s2);
        if(Double.compare(hDegree, mDegree) == 0 || Double.compare(mDegree, sDegree) == 0) count++;
        
        
        return count;
        
        
    }
    
    // 1초 이후에 겹쳐진 시각을 카운팅하기
    static int timePast() {
        
        int res = 0;
        
        double prevH = hDegree;
        double prevM = mDegree;
        double prevS = sDegree;
        
        hDegree += (1.0 / 120);
        mDegree += 0.1;
        sDegree += 6.0;
        
        if(Double.compare(prevH, prevS) > 0 && Double.compare(hDegree, sDegree) <= 0) res++;
        if(Double.compare(prevM, prevS) > 0 && Double.compare(mDegree, sDegree) <= 0) res++;
        if((Double.compare(prevH, prevM) > 0 && Double.compare(prevH, prevS) > 0)
            && (Double.compare(hDegree, mDegree) <= 0 && Double.compare(hDegree, sDegree) <= 0)) res--;
        
        if(hDegree >= 360) hDegree %= 360;
        if(mDegree >= 360) mDegree %= 360;
        if(sDegree >= 360) sDegree %= 360;
        
        
        
        return res;
    }
    
    static void calculateDegree(int h, int m, int s) {
        hDegree =  (h % 12) * 30.0 + m * 0.5 + s * (1.0 / 120);
        mDegree = m * 6.0 + s * 0.1;
        sDegree = s * 6.0;
    }
}