import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        int N, M;
        for (int tc = 0; tc < T; tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            if (M / 2 < N) N = M - N;

            long res = 1;

            for (int i = M-N+1; i <= M; i++) res *= i;
            for (int i = 1; i <= N; i++) res /= i;
            System.out.println(res);
        }
    }
}