import java.io.*;
import java.util.*;

/**
 * packageName    : _241226
 * fileName       : BOJ_G1_13460_구슬탈출2
 * author         : moongi
 * date           : 12/26/24
 * description    :
 */
public class Main {
    static int N, M, holeX, holeY;
    static char[][] arr;
    static boolean[][][][] visited;

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static Ball red, blue;


    static class Ball {
        int rx, ry, bx, by, cnt;
        public Ball(int rx, int ry, int bx, int by, int cnt) {
            this.rx = rx;
            this.ry = ry;
            this.bx = bx;
            this.by = by;
            this.cnt = cnt;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new char[N][M];
        visited = new boolean[N][M][N][M];

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                arr[i][j] = str.charAt(j);

                if (arr[i][j] == '0') {
                    holeX = i;
                    holeY = j;
                } else if (arr[i][j] == 'R') {
                    red = new Ball(i, j, 0, 0, 0);
                } else if (arr[i][j] == 'B') {
                    blue = new Ball(0, 0, i, j, 0);
                }
            }
        }
        System.out.println(moveBall());

    }

    static int moveBall() {
        ArrayDeque<Ball> q = new ArrayDeque<>();
        q.offer(new Ball(red.rx, red.ry, blue.bx, blue.by, 1));
        visited[red.rx][red.ry][blue.bx][blue.by] = true;

        while (!q.isEmpty()) {
            Ball curr = q.poll();

            int cRx = curr.rx;
            int cRy = curr.ry;
            int cBx = curr.bx;
            int cBy = curr.by;
            int cnt = curr.cnt;

            if (cnt > 10) {
                return -1;
            }

            for (int d = 0; d < 4; d++) {
                int nRx = cRx;
                int nRy = cRy;
                int nBx = cBx;
                int nBy = cBy;

                boolean isRed = false;
                boolean isBlue = false;

                while (arr[nRx + dx[d]][nRy + dy[d]] != '#') {
                    nRx += dx[d];
                    nRy += dy[d];

                    // 구멍에 도착했을 경우
                    if (arr[nRx][nRy] == 'O') {
                        isRed = true;
                        break;
                    }
                }

                while (arr[nBx + dx[d]][nBy + dy[d]] != '#') {
                    nBx += dx[d];
                    nBy += dy[d];

                    if (arr[nBx][nBy] == 'O') {
                        isBlue = true;
                        break;
                    }
                }

                if (isBlue) {
                    continue;
                }

                if (isRed && !isBlue) {
                    return cnt;
                }

                if (nRx == nBx && nRy == nBy) {
                    if (d == 0) {
                        if (cRx > cBx) nRx -= dx[d];
                        else nBx -= dx[d];
                    } else if (d == 1) {
                        if (cRy < cBy) nRy -= dy[d];
                        else nBy -= dy[d];
                    } else if (d == 2) {
                        if (cRx > cBx) nBx -= dx[d];
                        else nRx -= dx[d];
                    } else {
                        if (cRy < cBy) nBy -= dy[d];
                        else nRy -= dy[d];
                    }
                }

                if (!visited[nRx][nRy][nBx][nBy]) {
                    visited[nRx][nRy][nBx][nBy] = true;
                    q.add(new Ball(nRx, nRy, nBx, nBy, cnt + 1));
                }
            }

        }

        return -1;
    }
}