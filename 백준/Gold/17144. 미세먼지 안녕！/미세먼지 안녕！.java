import java.io.*;
import java.util.*;

public class Main {
    static int R, C, T;
    static int[][] arr;
    static int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb;

        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        arr = new int[R][C];
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < T; i++) {
            spreadDust();
            airCondition();
        }

        int res = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                res += arr[i][j];
        System.out.println(res+2);
    }
    static void spreadDust() {
        int[][] tmp = new int[R][C];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (arr[i][j] > 0) {
                    int v = arr[i][j];
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (nx >= 0 && nx < R && ny >= 0 && ny < C && arr[nx][ny] >= 0) {
                            v -= arr[i][j]/5;
                            tmp[nx][ny] += arr[i][j] / 5;
                        }
                    }
                    arr[i][j] = v;
                }
            }
        }
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                arr[i][j] += tmp[i][j];
    }
    static void airCondition() {
        int uX = 0, uY = 0, dX = 0, dY = 0;
        for (int i = 0; i < R; i++) {
            if(arr[i][0] == -1) {
                uX = i;
                uY = 0;
                dX = i+1;
                dY = 0;
                break;
            }
        }
        
        dx = new int[]{0, -1, 0, 1}; dy = new int[]{1, 0, -1, 0};
        int tmp1 = arr[uX][C - 1];
        int tmp2 = arr[0][C - 1];
        int tmp3 = arr[0][0];

        for (int i = C-1; i > 1; i--)
            arr[uX][i] = arr[uX][i - 1];
        arr[uX][1] = 0;

        for (int i = 0; i < uX-1; i++)
            arr[i][C - 1] = arr[i + 1][C - 1];
        arr[uX - 1][C - 1] = tmp1;

        for (int i = 0; i < C - 2; i++)
            arr[0][i] = arr[0][i + 1];
        arr[0][C - 2] = tmp2;

        for (int i = uX-1; i > 1; i--)
            arr[i][0] = arr[i - 1][0];
        arr[1][0] = tmp3;

        dx = new int[]{0, 1, 0, -1}; dy = new int[]{1, 0, -1, 0};

        tmp1 = arr[dX][C - 1];
        tmp2 = arr[R - 1][C - 1];
        tmp3 = arr[R - 1][0];
        for (int i = C-1; i > 1; i--)
            arr[dX][i] = arr[dX][i - 1];
        arr[dX][1] = 0;

        for (int i = R-1; i > dX+1; i--)
            arr[i][C - 1] = arr[i - 1][C - 1];
        arr[dX+1][C - 1] = tmp1;

        for (int i = 0; i < C - 2; i++)
            arr[R - 1][i] = arr[R - 1][i + 1];
        arr[R - 1][C - 2] = tmp2;

        for (int i = dX+1; i < R - 2; i++)
            arr[i][0] = arr[i + 1][0];
        arr[R - 2][0] = tmp3;
    }
}