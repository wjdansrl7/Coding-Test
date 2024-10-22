import java.io.*;
import java.util.*;

/**
 * packageName    : _241021
 * fileName       : BOJ_G3_9466_텀프로젝트
 * author         : moongi
 * date           : 10/22/24
 * description    :
 */
public class Main {
    static int res, N;
    static int[] p;
    static boolean[] visited, done;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {
            res = 0;
            N = Integer.parseInt(br.readLine());
            p = new int[N +1];
            visited = new boolean[N + 1];
            done = new boolean[N + 1];

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i < N + 1; i++) {
                p[i] = Integer.parseInt(st.nextToken());
            }

            for (int i = 1; i < N + 1; i++) {
                if (done[i]) continue;
                dfs(i);
            }
            System.out.println(N - res);
        }

    }

    static void dfs(int idx) {
        if (done[idx]) return;

        if (visited[idx]) {
            done[idx] = true;
            res++;
        }
        visited[idx] = true;
        dfs(p[idx]);
        done[idx] = true;
        visited[idx] = false;
    }
}