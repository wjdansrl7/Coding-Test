
import java.io.*;
import java.util.*;

public class Main {
	static int N, M;
	static int[][] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N + 1][M + 1];
		int[][] dp = new int[N + 1][M + 1];
		int res = 0;

		for (int i = 1; i < N+1; i++) {
			String str = br.readLine();
			for (int j = 1; j < M+1; j++) {
				arr[i][j] = str.charAt(j-1) - '0';

				if (arr[i][j] == 1) {
					dp[i][j] = Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					res = dp[i][j] > res ? dp[i][j] : res;
				}
			}
		}

		System.out.println(res * res);
	}
}
