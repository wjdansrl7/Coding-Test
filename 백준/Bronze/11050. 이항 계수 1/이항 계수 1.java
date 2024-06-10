import java.util.*;
import java.io.*;

public class Main {
    static int combination(int n, int r) {
        if (n == r || r == 0) return 1;

        return combination(n - 1, r - 1) + combination(n - 1, r);
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        System.out.println(combination(N, K));
    }
}