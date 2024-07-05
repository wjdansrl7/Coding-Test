import java.io.*;
import java.util.*;

public class Main {
    static int N, K, res = -1;
    static char[][] arr;
    static boolean[][] visited;
    static int[] dx = {-1,0,1,0}, dy = {0, 1, 0, -1};

    static class State {
        int x, y, status;

        public State(int x, int y, int status) {
            this.x = x;
            this.y = y;
            this.status = status;
        }

    }
    static ArrayDeque<State> q;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {
            st = new StringTokenizer(br.readLine());
            res = -1;

            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            arr = new char[K+2][N+2];
            visited = new boolean[K+2][N+2];

            q = new ArrayDeque<>();
            int st_x = 0, st_y = 0;
            for (int i = 1; i < K+1; i++) {
                String str = br.readLine();
                for (int j = 1; j < N+1; j++) {
                    arr[i][j] = str.charAt(j-1);

                    if (arr[i][j] == '@') {
                        st_x = i;
                        st_y = j;
                    } else if (arr[i][j] == '*') {
                        q.offer(new State(i, j, -1));
                        visited[i][j] = true;
                    }
                }
            }

            visited[st_x][st_y] = true;
            q.offer(new State(st_x, st_y, 0));

            BFS();

            if (res == -1) sb.append("IMPOSSIBLE").append('\n');
            else sb.append(res).append('\n');

        }
        System.out.println(sb);
    }

    private static void BFS() {

        while (!q.isEmpty()) {
            State p = q.poll();

            if (p.status != -1 && (p.x < 1 || p.x > K || p.y < 1 || p.y > N)) {
                res = p.status;
                return;
            }

            // 불인 경우
            if (p.status == -1) {

                for (int d = 0; d < 4; d++) {
                    int nx = p.x + dx[d];
                    int ny = p.y + dy[d];

                    if (nx >= 1 && nx <= K && ny >= 1 && ny <= N && !visited[nx][ny] && arr[nx][ny] != '#') {
                        visited[nx][ny] = true;
                        q.offer(new State(nx, ny, -1));
                    }

                }
            } else {
                // 상근이의 이동할 위치
                for (int d = 0; d < 4; d++) {
                    int nx = p.x + dx[d];
                    int ny = p.y + dy[d];

                    if (!visited[nx][ny] && arr[nx][ny] != '#') {
                        if (nx >= 1 && nx <= K && ny >= 1 && ny <= N) visited[nx][ny] = true;
                        q.offer(new State(nx, ny, p.status + 1));
                    }
                }
            }


        }

    }
}