import java.util.*;
import java.io.*;

/**
[코드 번호, 제조일, 최대 수량, 현재 수량]
[code, date, maximum, remain]
ext: 기준이 되는 데이터
val_ext: 뽑아낼 정보의 기준값보다 작은 데이터를 뽑은 후
sort_by: 정렬할 기준이 되는 문자열, 오름차순 정렬할 예정

*/

class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        int size = 0;
        if(ext.equals("code")) {
            Arrays.sort(data, (o1, o2) -> o1[0] - o2[0]);
            
            for(int i = 0; i < data.length; i++) {
                if(data[i][0] <= val_ext) size++;
            }
        } else if(ext.equals("date")) {
            Arrays.sort(data, (o1, o2) -> o1[1] - o2[1]);
            
            for(int i = 0; i < data.length; i++) {
                if(data[i][1] <= val_ext) size++;
            }
        } else if (ext.equals("maximum")) {
            Arrays.sort(data, (o1, o2) -> o1[2] - o2[2]);
            
            for(int i = 0; i < data.length; i++) {
                if(data[i][2] <= val_ext) size++;
            }
        } else {
            Arrays.sort(data, (o1, o2) -> o1[3] - o2[3]);
            
            for(int i = 0; i < data.length; i++) {
                if(data[i][3] <= val_ext) size++;
            }
        }
        
        int[][] res = new int[size][4];
        
        for(int i = 0; i < size; i++) {
            res[i][0] = data[i][0];
            res[i][1] = data[i][1];
            res[i][2] = data[i][2];
            res[i][3] = data[i][3];
        }
        
        //code, date, maximum, remain
        if(sort_by.equals("code")) {
            Arrays.sort(res, (o1, o2) -> o1[0] - o2[0]);
        } else if (sort_by.equals("date")) {
            Arrays.sort(res, (o1, o2) -> o1[1] - o2[1]);
        } else if(sort_by.equals("maximum")) {
            Arrays.sort(res, (o1, o2) -> o1[2] - o2[2]);
        } else {
            Arrays.sort(res, (o1, o2) -> o1[3] - o2[3]);
        }
        
        
        return res;
        
        
        
    }
}