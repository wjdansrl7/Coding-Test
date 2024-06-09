import java.util.*;
import java.io.*;

public class Main {
    static char[][] arr;
    static int R, C, res = Integer.MAX_VALUE;
    static int[] start;
    static List<int[]> waters;
    static boolean[][] wVisited;
    static int[] dx = {-1,0,1,0}, dy = {0, 1, 0, -1};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        arr = new char[R][C];

        waters = new ArrayList<>();
        wVisited = new boolean[R][C];
        start = new int[2];

        for (int i = 0; i < R; i++) {
            String str = br.readLine();
            for (int j = 0; j < C; j++) {
                arr[i][j] = str.charAt(j);

                // 고슴도치의 위치
                if (arr[i][j] == 'S') {
                    start[0] = i;
                    start[1] = j;
                }
                if (arr[i][j] == '*') {
                    waters.add(new int[]{i, j});
                    wVisited[i][j] = true;
                }
            }
        }

        BFS(start[0], start[1]);

        if (res == Integer.MAX_VALUE) System.out.println("KAKTUS");
        else System.out.println(res);

    }

    static void BFS(int x, int y) {
        ArrayDeque<int[]> q = new ArrayDeque<>();
        boolean[][] v = new boolean[R][C];
        List<int[]> tmp;
        q.offer(new int[]{x, y, 0});
        v[x][y] = true;

        while (true) {
            int size = waters.size();
            for(int i = 0; i < size; i++) {
                for (int d = 0; d < 4; d++) {
                    int nx = waters.get(i)[0] + dx[d];
                    int ny = waters.get(i)[1] + dy[d];

                    // 다음 위치가 돌이거나, 비버의 굴, 범위를 벗어나는 경우
                    if (nx < 0 || nx >= R || ny < 0 || ny>= C || arr[nx][ny] == 'X' || arr[nx][ny] == 'D' || wVisited[nx][ny]) continue;
                    arr[nx][ny] = '*';
                    wVisited[nx][ny] = true;
                    waters.add(new int[]{nx, ny});
                }
            }
            tmp = new ArrayList<>();
            while(!q.isEmpty()) {
            // 고슴도치의 현재 위치
            int[] p = q.poll();

            if (arr[p[0]][p[1]] == 'D') {
                res = res > p[2] ? p[2] : res;
                return;
            }

            for (int d = 0; d < 4; d++) {
                int nx = p[0] + dx[d];
                int ny = p[1] + dy[d];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C || arr[nx][ny] == 'X' || arr[nx][ny] == '*' || v[nx][ny]) continue;

                v[nx][ny] = true;
                tmp.add(new int[]{nx, ny, p[2]+1});
            }
            }
            for (int[] t : tmp) q.offer(t);
            if (tmp.isEmpty()) return;
        }
    }
}