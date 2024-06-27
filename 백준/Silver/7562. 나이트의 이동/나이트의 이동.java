import java.util.*;
import java.io.*;
public class Main {
    static int[] dx = {-2,-1, 1, 2, 2, 1, -1, -2}, dy = {1, 2, 2, 1, -1, -2, -2, -1};
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {

            int l = Integer.parseInt(br.readLine());
            int[][] arr = new int[l][l];

            st = new StringTokenizer(br.readLine());
            int st_x = Integer.parseInt(st.nextToken());
            int st_y = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            int et_x = Integer.parseInt(st.nextToken());
            int et_y = Integer.parseInt(st.nextToken());

            ArrayDeque<int[]> q = new ArrayDeque<>();
            q.offer(new int[]{st_x, st_y, 0});

            boolean[][] visited = new boolean[l][l];
            visited[st_x][st_y] = true;

            int res = 90002;
            while (!q.isEmpty()) {
                int[] p = q.poll();

                if (p[0] == et_x && p[1] == et_y) {
                    res = res > p[2] ? p[2] : res;
                    continue;
                }

                for (int d = 0; d < 8; d++) {
                    int nx = p[0] + dx[d];
                    int ny = p[1] + dy[d];

                    if (nx < 0 || nx >= l || ny < 0 || ny >= l || visited[nx][ny]) continue;

                    q.offer(new int[]{nx, ny, p[2]+1});
                    visited[nx][ny] = true;
                }
            }
            if (res == 90002) sb.append(0).append('\n');
            else sb.append(res).append('\n');
        }
        System.out.println(sb);
    }
}