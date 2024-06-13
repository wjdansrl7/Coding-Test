import java.util.*;
import java.io.*;

public class Main {
    static int N, res = 0;
    static int[] order;
    static int[][] result;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        order = new int[9];
        order[3] = 0;

        boolean[] v = new boolean[9];
        v[0] = true;

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        // 이닝수에 따른 결과
        result = new int[N][9];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++) {
                result[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        permutation(0, v);
        System.out.println(res);
    }

    static void permutation(int cnt, boolean[] visited) {
        if (cnt == 9) {
            playGame(order);
            return;
        }
        if (cnt == 3) {
            permutation(cnt + 1, visited);
        } else {
            for (int i = 1; i < 9; i++) {
                if (visited[i]) continue;
                order[cnt] = i;
                visited[i] = true;
                permutation(cnt + 1, visited);
                visited[i] = false;
            }
        }
    }
    static void playGame(int[] order) {
        int out = 0, idx = 0;
        boolean[] ground = new boolean[4];

        int score = 0;
        for (int i = 0; i < N; i++) {
            // 새로운 이닝에서는 0 out, ground는 비어있어야 된다.
            out = 0;
            for (int j = 0; j < 4; j++) {
                ground[j] = false;
            }
            while (out != 3) {
                // 현재 타자에 나온 선수 등번호
                int playerNum = order[idx++ % 9];
                // 해당 이닝에서 선수에 공을 친 결과
                int curResult = result[i][playerNum];

                // 아웃된 경우
                if (curResult == 0){
                    out++;
                    continue;
                }

                // 그라운드에 있는 주자들을 기준으로 for문 생성
                for (int j = 3; j >= 1; j--) {
                    // 해당 루에 선수가 있는 경우
                    if (ground[j]) {
                        if (j + curResult >= 4) {
                            // 홈에 들어왔으므로 득점으로 인정
                            ground[j] = false;
                            score++;
                        } else {
                            // 진루만 하는 경우
                            ground[j] = false;
                            ground[j+curResult] = true;
                        }
                    }
                }
                // 현재 친 선수가 홈런을 친 경우
                if (curResult==4) score++;
                else ground[curResult] = true;
            }
        }
        res = score > res ? score : res;
    }
}