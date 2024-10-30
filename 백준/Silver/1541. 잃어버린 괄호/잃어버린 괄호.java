import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer sub = new StringTokenizer(br.readLine(), "-");
        int sum = Integer.MAX_VALUE;
        
        while (sub.hasMoreTokens()) {
            StringTokenizer add = new StringTokenizer(sub.nextToken(), "+");
            int temp = 0;
            
            while (add.hasMoreTokens()) temp += Integer.parseInt(add.nextToken());
            if (sum == Integer.MAX_VALUE) sum = temp;
            else sum -= temp;
        }
        System.out.println(sum);
    }
}