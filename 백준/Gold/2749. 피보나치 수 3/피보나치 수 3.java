import java.io.*;

// 피사노 주기를 활용하는 문제 K(m) = 15 * 10^(m-1)
public class Main {
    static long[] F;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        int idx = (int) (n % 1500000);
        F = new long[idx+1];

        F[0] = 0;
        F[1] = 1;

        for (int i = 2; i < idx+1; i++) {
            F[i] = (F[i - 1] + F[i - 2]) % 1_000_000;
        }
        System.out.println(F[idx]);
    }
}