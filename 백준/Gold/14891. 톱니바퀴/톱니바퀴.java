import java.io.*;
import java.util.*;

/**
 * N극은 0, S극은 1
 * 회전 횟수: K(1 <= K <= 100),
 * 톱니바퀴의 번호, 방향(1인 경우, 시계 방향, -1인 경우, 반시계 방향)
 */
public class Main {
    static int[][] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        arr = new int[4][8];

        for (int i = 0; i < 4; i++) {
            String str = br.readLine();
            for (int j = 0; j < 8; j++) {
                arr[i][j] = str.charAt(j) - '0';
            }
        }
        int K = Integer.parseInt(br.readLine());

        // -1인 경우 반시계, 1인 경우 시계 방향
        int num, dir;
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            num = Integer.parseInt(st.nextToken());
            dir = Integer.parseInt(st.nextToken());

            play(num, dir);
        }
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            if (arr[i][0] == 1) { // N은 0, S는 1
                sum += (int) Math.pow(2, i);
            }
        }
        System.out.println(sum);
    }
    private static void play(int num, int dir) {
        // 방향이 반시계냐(-1), 시계방향이냐(1)
        int curDir = dir;
        int[] dd = new int[4];
        dd[num-1] = dir;
        for (int i = num - 1; i > 0; i--) {
            if (arr[i][6] != arr[i - 1][2]) {
                curDir = -curDir;
                dd[i - 1] = curDir;
            } else {
                // 회전하지 않고 멈춘다.
                break;
            }
        }
        // 오른쪽 방향
        curDir = dir;
        for (int i = num - 1; i < 3; i++) {
            if (arr[i][2] != arr[i + 1][6]) {
                curDir = -curDir;
                dd[i + 1] = curDir;
            } else {
                // 회전하지 않고 멈춘다.
                break;
            }
        }

        for (int i = 0; i < 4; i++) {
            if (dd[i] == 1) {
                // 시계 방향으로 돌아야함.
                int tmp = arr[i][7];
                for (int j = 7; j > 0; j--) {
                    arr[i][j] = arr[i][j-1];
                }
                arr[i][0] = tmp;
            } else if (dd[i] == -1){
                // 반시계로 돌아야함.
                int tmp = arr[i][0];
                for (int j = 0; j < 8; j++) {
                    arr[i][j] = arr[i][(j + 1) % 8];
                }
                arr[i][7] = tmp;
            }
        }
    }
}