import java.io.*;
import java.util.*;

/**
 * packageName    : _241226
 * fileName       : BOJ_G4_9019_DSLR
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
            sb.append(solve(A, B)).append('\n');
        }
        System.out.println(sb);

    }
    static class Register {
        int num;
        String command;
        public Register(int num, String command) {
            this.num = num;
            this.command = command;
        }
    }
    static Register executeCommand(int n, String command, int d) {
        int d1 = n / 1000;
        int d2 = (n % 1000) / 100;
        int d3 = (n % 100) / 10;
        int d4 = n % 10;

        if (d == 0) return new Register((2 * n) % 10_000, command.concat("D"));
        else if (d == 1) {
            if (n == 0) return new Register(9999, command.concat("S"));
            else return new Register(n - 1, command.concat("S"));
        } else if (d == 2) return new Register(d2 * 1000 + d3 * 100 + d4 * 10 + d1, command.concat("L"));
        else return new Register(d4 * 1000 + d1 * 100 + d2 * 10 + d3, command.concat("R"));
    }
    static String solve(int a, int b) {
        ArrayDeque<Register> q = new ArrayDeque<>();
        boolean[] visited = new boolean[10000];

        q.offer(new Register(a, ""));
        visited[a] = true;

        while (!q.isEmpty()) {
            Register r = q.poll();

            if (r.num == b) return r.command;

            for (int d = 0; d < 4; d++) {
                Register executed = executeCommand(r.num, r.command, d);
                if (!visited[executed.num]) q.offer(executed);
                visited[executed.num] = true;
            }
        }
        return "";
    }
}