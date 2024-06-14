import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str = br.readLine();
        int[] arr = new int[5];
        for (int i = 1; i < 5; i++) arr[i] = i;
        
        char target;
        int tmp = 0;
        for (int i = 0; i < str.length(); i++) {
            target = str.charAt(i);
            if (target == 'A') {
                tmp = arr[1];
                arr[1] = arr[2];
                arr[2] = tmp;
            } else if (target == 'B') {
                tmp = arr[1];
                arr[1] = arr[3];
                arr[3] = tmp;
            } else if (target == 'C') {
                tmp = arr[1];
                arr[1] = arr[4];
                arr[4] = tmp;
            } else if (target == 'D') {
                tmp = arr[2];
                arr[2] = arr[3];
                arr[3] = tmp;
            } else if (target == 'E') {
                tmp = arr[2];
                arr[2] = arr[4];
                arr[4] = tmp;
            } else {
                tmp = arr[3];
                arr[3] = arr[4];
                arr[4] = tmp;
            }
        }
        int res1 = 0, res2 = 0;
        for (int i = 1; i < 5; i++) {
            if (arr[i] == 1) res1 = i;
            if (arr[i] == 4) res2 = i;
        }
        sb.append(res1).append('\n').append(res2);
        System.out.println(sb);
    }
}