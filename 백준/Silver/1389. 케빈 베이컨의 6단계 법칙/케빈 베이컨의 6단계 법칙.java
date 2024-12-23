import java.io.*;
import java.util.*;

/**
 * packageName    : _241223
 * fileName       : BOJ_S1_1389_케빈베이컨의6단계법칙
 * author         : moongi
 * date           : 12/23/24
 * description    :
 */
public class Main {
    static final int INF = 987654321;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] arr = new int[N + 1][N + 1];

        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                if (i == j) arr[i][j] = 0;
                else arr[i][j] = INF;
            }
        }

        int x, y;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            arr[x][y] = arr[y][x] = 1;
        }

        // 플로이드 워셜 알고리즘
        for (int k = 1; k < N + 1; k++) {
            for (int i = 1; i < N + 1; i++) {
                for (int j = 1; j < N + 1; j++) {
                    if (arr[i][j] > arr[i][k] + arr[k][j]) {
                        arr[i][j] = arr[i][k] + arr[k][j];
                    }
                }
            }
        }

        int res = INF;
        int idx = -1;
        for (int i = 1; i < N + 1; i++) {
            int total = 0;
            for (int j = 1; j < N + 1; j++) {
                total += arr[i][j];
            }
            if (res > total) {
                res = total;
                idx = i;
            }
        }
        System.out.println(idx);
    }
}