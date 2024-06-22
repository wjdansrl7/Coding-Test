import java.util.*;
import java.io.*;

// 지수법칙과 모듈러 연산 중요
public class Main {
    static int a, b, c;

    static long multiply(int a, int b, int c) {
        if (b == 1) return a % c;

        long res = multiply(a, b / 2, c);

        // long type을 벗어나므로 모듈러 합동 공식을 알고 있어야됨.
        if (b % 2 == 1) return (res * res % c) * a % c;

        return res * res % c;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        System.out.println(multiply(a,b,c));
    }
}