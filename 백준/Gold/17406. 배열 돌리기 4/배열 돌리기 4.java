import java.io.*;
import java.util.*;

/**
 * packageName    : _0203
 * fileName       : BOJ_G4_17406_배열돌리기444
 * author         : moongi
 * date           : 2/8/24
 * description    :
 */

public class Main {

    static int N, M, K, res = Integer.MAX_VALUE;
    static int[][] arr, rotationCnt;
    static int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

    static void Perm(int cnt, int[] order, boolean[] v) {
        if(cnt == K+1) {
            solution(order);
            return;
        }

        for (int i = 1; i <= K; i++) {
            if(v[i]) continue;
            v[i] = true;
            order[cnt] = i;
            Perm(cnt+1, order, v);
            v[i] = false;
        }
    }

    static void solution(int[] v) {
        int[][] tmp = rotation(v);

        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < M; k++)
                sum += tmp[j][k];
            res = res > sum ? sum : res;
        }
    }

    static int[][] rotation(int[] v) {
        int[][] tmp = copyArr();

        for (int k = 1; k <= K; k++) {
            int R = rotationCnt[v[k]][0];
            int C = rotationCnt[v[k]][1];
            int S = rotationCnt[v[k]][2];

            for (int s = 1; s <= S; s++) {

                int tmp1 = tmp[R - s][C + s];
                int tmp2 = tmp[R + s][C + s];
                int tmp3 = tmp[R + s][C - s];

                for (int j = C + s; j > C - s; j--) {
                    tmp[R - s][j] = tmp[R - s][j - 1];
                }

                for (int j = R + s; j > R - s; j--) {
                    tmp[j][C + s] = tmp[j - 1][C + s];
                }
                tmp[R - s + 1][C + s] = tmp1;

                for (int j = C - s; j < C + s; j++) {
                    tmp[R + s][j] = tmp[R + s][j + 1];
                }
                tmp[R + s][C + s - 1] = tmp2;

                for (int j = R - s; j < R + s; j++) {
                    tmp[j][C - s] = tmp[j + 1][C - s];
                }
                tmp[R + s - 1][C - s] = tmp3;
            }
        }

        return tmp;
    }

    static int[][] copyArr() {
        int[][] tmp = new int[N][M];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                tmp[i][j] = arr[i][j];
        return tmp;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        arr = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        rotationCnt = new int[K+1][3]; // k = 1부터 K개까지 저장하기 위해서

        for (int i = 1; i <= K; i++) {
            st = new StringTokenizer(br.readLine());
            rotationCnt[i][0] = Integer.parseInt(st.nextToken()) - 1;
            rotationCnt[i][1] = Integer.parseInt(st.nextToken()) - 1;
            rotationCnt[i][2] = Integer.parseInt(st.nextToken());
        }

        Perm(1, new int[K+1], new boolean[K+1]);

        System.out.println(res);
    }
}