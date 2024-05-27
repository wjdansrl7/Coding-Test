import java.io.*;
import java.util.*;

public class Main {
    static int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
    static int M, N;
    static int[][] arr;
    static boolean[][] v;
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = null;

        int T = Integer.parseInt(br.readLine());

        int K;
        for (int tc = 0; tc < T; tc++) {
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            arr = new int[M][N];
            v = new boolean[M][N];

            for (int i = 0; i < K; i++) {
                st = new StringTokenizer(br.readLine());
                arr[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = 1;
            }

            int res = 0;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (arr[i][j] == 1 && !v[i][j]) {
                        DFS(i, j);
                        res++;
                    }
                }
            }
            sb.append(res).append('\n');
        }
        System.out.println(sb);
    }

    static void DFS(int x, int y) {
        ArrayDeque<int[]> stk = new ArrayDeque<>();
        v[x][y] = true;
        stk.push(new int[]{x, y});

        while (!stk.isEmpty()) {
            int[] p = stk.pop();

            for (int d = 0; d < 4; d++) {
                int nx = p[0] + dx[d];
                int ny = p[1] + dy[d];

                if(nx >=0 && nx < M && ny >= 0 && ny < N) {
                    if (arr[nx][ny] == 1 && !v[nx][ny]) {
                        v[nx][ny] = true;
                        stk.push(new int[]{nx, ny});
                    }
                }
            }
        }
    }
}