import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) throws Exception {
        //System.setIn(new FileInputStream("res/swea_d6_1263.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {
            sb = new StringBuilder();
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());

            int[][] dist = new int[N + 1][N + 1];
            for (int i = 1; i < N + 1; i++) {
                for (int j = 1; j < N + 1; j++) {
                    dist[i][j] = Integer.parseInt(st.nextToken());
                    if(dist[i][j] == 0) dist[i][j] = 1_000_000;
                }
            }

            for (int k = 1; k < N + 1; k++) {
                for (int i = 1; i < N + 1; i++) {
                    if(i == k) continue;
                    for (int j = 1; j < N + 1; j++) {
                        if(j == k || i == j) continue;
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }

            int res = Integer.MAX_VALUE;
            for (int i = 1; i < N + 1; i++) {
                int sum = 0;
                for (int j = 1; j < N + 1; j++) {
                    if(i==j) continue;
                    sum += dist[i][j];
                }
                res = res > sum ? sum : res;
            }

            sb.append("#").append(tc+1).append(" ").append(res);
            System.out.println(sb);
        }
    }
}