import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] ni = {-1, 0, 1, 0}; // 북, 동, 남, 서
    static int[] nj = {0, 1, 0, -1};
    static int[][] arr = new int[51][51];
    static int answer = 0;

    static void clean(int x, int y, int dir) {
        if (arr[x][y] == 0) {
            answer++;
            arr[x][y] = 2;
        }
        int cnt = 0;
        for (int d = 0; d < 4; d++) {
            int nx = x + ni[d];
            int ny = y + nj[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
                EmptySpace(x, y, dir);
                break;
            }
            cnt++;
        }
        if(cnt == 4)
            notEmptySpace(x, y, dir);
    }

    static void EmptySpace(int x, int y, int dir) {
        if (dir - 1 >= 0) {
            dir--;
        } else {
            dir = 3;
        }
        int nx = x + ni[dir];
        int ny = y + nj[dir];

        if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if(arr[nx][ny] == 0) {
                clean(nx, ny, dir);
            } else {
                clean(x, y, dir);
            }
        }
    }

    static void notEmptySpace(int x, int y, int dir) {
        int tmp = -1;
        if(dir == 0) { // 북쪽
            tmp = 2;
        } else if (dir == 1) { // 동쪽
            tmp = 3;
        } else if (dir == 2) { // 남쪽
            tmp = 0;
        } else if (dir == 3) { // 서쪽
            tmp = 1;
        }

        int nx = x + ni[tmp];
        int ny = y + nj[tmp];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != 1) {
            clean(nx, ny, dir);
        } else {
            return;
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int dir = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        clean(x, y, dir);
        System.out.println(answer);
    }
}