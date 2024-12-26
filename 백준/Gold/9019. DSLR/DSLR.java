import java.io.*;
import java.util.*;
/**
 * packageName    : _241226
 * fileName       : BOJ_G4_9019_DSLR_timeSave
 * author         : moongi
 * date           : 12/26/24
 * description    :
 */
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        int A, B;
        for (int tc = 0; tc < T; tc++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            boolean[] visited = new boolean[10_000];
            ArrayDeque<Integer> q = new ArrayDeque<>();
            String[] command = new String[10_000];

            visited[A] = true;
            q.add(A);
            Arrays.fill(command, "");

            while (!q.isEmpty() && !visited[B]) {
                int curr = q.poll();

                int D = (2 * curr) % 10_000;
                int S = curr == 0 ? 9999 : curr - 1;
                int L = (curr % 1000) * 10 + curr / 1000;
                int R = (curr % 10) * 1000 + curr / 10;

                if (!visited[D]) {
                    q.offer(D);
                    visited[D] = true;
                    command[D] = command[curr] + "D";
                }
                if (!visited[S]) {
                    q.offer(S);
                    visited[S] = true;
                    command[S] = command[curr] + "S";
                }
                if (!visited[L]) {
                    q.offer(L);
                    visited[L] = true;
                    command[L] = command[curr] + "L";
                }
                if (!visited[R]) {
                    q.offer(R);
                    visited[R] = true;
                    command[R] = command[curr] + "R";
                }
            }
            sb.append(command[B]).append('\n');
        }
        System.out.println(sb);
    }
}