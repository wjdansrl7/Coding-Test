import java.util.*;
import java.io.*;
/**
 * packageName    : _250105
 * fileName       : BOJ_G3_10986_나머지합
 * author         : moongi
 * date           : 1/5/25
 * description    :
 */
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        long res = 0;

        long[] S = new long[N + 1];
        long[] cnt = new long[M];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i < N + 1; i++) {
            S[i] = (S[i - 1] + Integer.parseInt(st.nextToken())) % M;

            if (S[i] == 0) res++;
            cnt[(int) S[i]]++;
        }
        for (int i = 0; i < M; i++) {
            if (cnt[i] > 1) {
                res += cnt[i] * (cnt[i] - 1) / 2;
            }
        }
        System.out.println(res);
    }
}
