import java.io.*;
import java.util.*;

public class Solution {
    static int N, res;
    static int[][] pan;
    static int[] dx = {-1,0,1,0}, dy = {0, 1, 0, -1};
    static List<int[]>[] wormHole = new ArrayList[5];
    static int[][] block = {{0, 0, 0, 0}, {2, 3, 1, 0}, {1, 3, 0, 2}, {3, 2, 0, 1}, {2, 0, 3, 1}, {2, 3, 0, 1}};
    public static void main(String[] args) throws Exception {
//        System.setIn(new FileInputStream("/Users/moongi/Desktop/SSAFY/work_algo/res/input_swea_5650.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        StringBuilder sb;

        int T = Integer.parseInt(br.readLine().trim());
        List<int[]> start;
        for (int tc = 0; tc < T; tc++) {
            sb = new StringBuilder();
            start = new ArrayList<>();
            N = Integer.parseInt(br.readLine().trim());
            pan = new int[N][N];
            res = 0;

            for (int i = 0; i < 5; i++)
                wormHole[i] = new ArrayList<>();

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine().trim());
                for (int j = 0; j < N; j++) {
                    pan[i][j] = Integer.parseInt(st.nextToken());
                    if(pan[i][j]==0) start.add(new int[]{i, j});
                    else if(pan[i][j]>=6) wormHole[pan[i][j] - 6].add(new int[]{i, j});
                }
            }

            for (int[] p : start)
                for (int d = 0; d < 4; d++)
                    pinball(p[0], p[1], d);
            sb.append("#").append(tc+1).append(" ").append(res);
            System.out.println(sb);
        }
    }

    static void pinball(int x, int y, int d) {
        int st_x = x;
        int st_y = y;
        int cnt = 0, score = 0;
        while (true){
            if (st_x == x && st_y == y && cnt != 0)
                break;

            x += dx[d];
            y += dy[d];
            cnt++;

            // 벽에 부딫힌 경우
            if (x < 0 || x > N-1 || y < 0 || y > N-1) {
                x -= dx[d];
                y -= dy[d];
                d = (d+2) % 4;
                score++;
            }
            // 빈 공간
            if(pan[x][y]==0)
                continue;
            if(pan[x][y] == -1) break; // 블랙홀
            if(pan[x][y] > 0 && pan[x][y] < 6) { // 블록
                int type = pan[x][y];
                score++; // 부딫힌 횟수 증가
                d = block[type][d]; // 방향 전환
                continue;
            }
            if(pan[x][y]>5){ // 웜홀
                int type = pan[x][y] - 6;
                int hx = wormHole[type].get(0)[0];
                int hy = wormHole[type].get(0)[1];

                int hx2 = wormHole[type].get(1)[0];
                int hy2 = wormHole[type].get(1)[1];

                if (x == hx && y == hy) {
                    x = hx2;
                    y = hy2;
                } else {
                    x = hx;
                    y = hy;
                }
            }
        }
        if(res < score) res = score;
    }
}