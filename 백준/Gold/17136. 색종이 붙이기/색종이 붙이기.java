import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * packageName    : wjdansrl7._240603
 * fileName       : BOJ_G2_17136_색종이붙이기2
 * author         : moongi
 * date           : 6/4/24
 * description    :
 */
public class Main {
    static int[][] pan;
    static int[] paper = {0, 5, 5, 5, 5, 5};
    static int res = 102;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        pan = new int[10][10];

        for (int i = 0; i < 10; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 10; j++) {
                pan[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        DFS(0, 0, 0);

        if (res != 102){ System.out.println(res);}
        else System.out.println(-1);





    }

    // DFS + backTracking
    static void DFS(int x, int y, int cnt) {
        if (x >= 9 && y > 9) {
            res = Math.min(res, cnt);
            return;
        }
        if (res <= cnt) return;

        if (y > 9) {
            DFS(x + 1, 0, cnt);
            return;
        }

        if (pan[x][y] == 1) {
            for (int i = 5; i >= 1; i--) {
                if (paper[i] > 0 && isValid(x, y, i)) {
                    attach(x, y, i, 0); // 색종이를 붙임.
                    paper[i]--;
                    DFS(x, y + 1, cnt + 1);
                    attach(x, y, i, 1); // 색종이를 다시 뗌.
                    paper[i]++;
                }
            }
        } else {
            DFS(x, y + 1, cnt);
        }
    }

    static void attach(int x, int y, int cnt, int state) {
        for (int i = x; i < x + cnt; i++) {
            for (int j = y; j < y + cnt; j++) {
                pan[i][j] = state;
            }
        }
    }

    static boolean isValid(int x, int y, int cnt) {
        for (int i = x; i < x + cnt; i++) {
            for (int j = y; j < y + cnt; j++) {
                if (i < 0 || i >= 10 || j < 0 || j >= 10) return false;
                if (pan[i][j] != 1) return false;
            }
        }
        return true;
    }
}