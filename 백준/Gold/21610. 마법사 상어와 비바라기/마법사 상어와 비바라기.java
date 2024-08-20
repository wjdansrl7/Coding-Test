import java.io.*;
import java.util.*;

public class Main {

    static int[] dx = {0, -1, -1, -1, 0, 1, 1, 1};
    static int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};

    static int N, M;
    static int[][] arr;
    static boolean[][] visited;
    static ArrayDeque<int[]> q = new ArrayDeque<>();

    // 대각선: 1,3,5,7
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N][N];
        visited = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int d, s;

        q.offer(new int[]{N-1, 0});
        q.offer(new int[]{N-1, 1});
        q.offer(new int[]{N-2, 0});
        q.offer(new int[]{N-2, 1});

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            d = Integer.parseInt(st.nextToken());
            s = Integer.parseInt(st.nextToken());

            visited = new boolean[N][N];
            moveCloud(d, s);
        }

        int sum = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sum +=arr[i][j];
            }
        }
        System.out.println(sum);
    }

    static void moveCloud(int dir, int s) {
        ArrayDeque<int[]> q2 = new ArrayDeque<>();
        while (!q.isEmpty()) {
            int[] cur = q.poll();

            int nx = cur[0] + dx[dir-1] * s;
            if (nx < 0) {
                nx = N + nx % N;
                if (nx == N) nx = 0;
            } else {
                nx = nx % N;
            }

            int ny = cur[1] + dy[dir-1] * s;
            if (ny < 0) {
                ny = N + ny % N;
                if (ny == N) ny = 0;
            } else {
                ny = ny % N;
            }
            arr[nx][ny]++;
            q2.offer(new int[]{nx, ny});
            visited[nx][ny] = true;
        }
        // 물복사 버그
        while (!q2.isEmpty()) {
            int[] cur = q2.poll();

            for (int i = 1; i < 8; i+=2) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if (isCheck(nx, ny) && arr[nx][ny] >= 1) {
                    arr[cur[0]][cur[1]]++;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] >= 2 && !visited[i][j]) {
                    arr[i][j] -= 2;
                    q.offer(new int[]{i, j});
                }
            }
        }
    }

    static boolean isCheck(int x, int y) {
        if (x >= 0 && x < N && y >= 0 && y < N) return true;
        return false;
    }
}