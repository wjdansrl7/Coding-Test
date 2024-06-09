import java.io.*;
import java.util.*;

public class Main {
    static int N, M, res = Integer.MAX_VALUE;
    static char[][] arr;
    static int[] start;
    static int[] dx = {-1,0,1,0}, dy = {0, 1, 0, -1};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new char[N][M];
        start = new int[2];
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                arr[i][j] = str.charAt(j);
                if (arr[i][j] == '0') {
                    start[0] = i;
                    start[1] = j;
                }
            }
        }
        BFS(start[0], start[1]);

        if (res == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(res);
    }

    static void BFS(int x, int y) {
        ArrayDeque<int[]> q = new ArrayDeque<>();
        boolean[][][] visited = new boolean[N][M][64];

        visited[x][y][0] = true;
        q.offer(new int[]{x, y, 0, 0});

        while (!q.isEmpty()) {
            int[] p = q.pop();

            if (arr[p[0]][p[1]] == '1') {
                res = res > p[2] ? p[2] : res;
                return;
            }

            for (int d = 0; d < 4; d++) {
                int nx = p[0] + dx[d];
                int ny = p[1] + dy[d];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (visited[nx][ny][p[3]] || arr[nx][ny] == '#') continue;

                if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'f') {
                    int nextKey = p[3] | (1 << (arr[nx][ny] - 'a'));
                    visited[nx][ny][nextKey] = true;
                    q.offer(new int[]{nx, ny, p[2] + 1, nextKey});
                } else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'F') {
                    if ((p[3] & 1 << (arr[nx][ny] - 'A')) == (int) Math.pow(2, arr[nx][ny] - 'A')) {
                        visited[nx][ny][p[3]] = true;
                        q.offer(new int[]{nx, ny, p[2] + 1, p[3]});
                    }
                } else {
                    visited[nx][ny][p[3]] = true;
                    q.offer(new int[]{nx, ny, p[2] + 1, p[3]});
                }
            }
        }
    }
}