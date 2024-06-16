import java.math.BigInteger;
import java.util.*;
import java.io.*;
public class Main {
    static int n;
    static BigInteger[] F;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        if (n <= 1) {
            System.out.println(n);
        } else {
            F = new BigInteger[n+1];

            F[0] = BigInteger.ZERO;
            F[1] = BigInteger.ONE;

            for (int i = 2; i < n + 1; i++) {
                F[i] = F[i - 2].add(F[i - 1]);
            }
            System.out.println(F[n]);
        }
    }
}