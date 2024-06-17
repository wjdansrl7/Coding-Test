import java.util.*;
import java.io.*;
public class Main {
    static double R;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Double.parseDouble(st.nextToken());
        
        System.out.printf("%.6f\n", R*R*Math.PI);
        System.out.printf("%.6f",R*R*2);
    }
}