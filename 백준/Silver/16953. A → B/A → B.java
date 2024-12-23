import java.io.*;
import java.util.*;
/**
 * packageName    : _241223
 * fileName       : BOJ_S2_A_B
 * author         : moongi
 * date           : 12/23/24
 * description    :
 */
public class Main {
    static int res = Integer.MAX_VALUE;
    static Long A, B;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = Long.parseLong(st.nextToken());
        B = Long.parseLong(st.nextToken());

        Solve(A, B, 0);
        if (res == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(res + 1);
    }

    static void Solve(Long curr, Long target, int cnt) {
        if (curr > target) return;

        if (curr.equals(target)) {
            if (res > cnt) res = cnt;
            return;
        }

        Solve(curr * 2, target, cnt + 1);
        Solve(curr * 10 + 1, target, cnt + 1);
    }
}