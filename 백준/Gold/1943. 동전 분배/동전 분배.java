
import java.util.*;
import java.io.*;

public class Main {
	static class Coin {
		int amount;
		int cnt;

		public Coin(int amount, int cnt) {
			this.amount = amount;
			this.cnt = cnt;
		}
	}

	static Coin[] coins;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;

		int N, amount, cnt, sum;
		for (int tc = 0; tc < 3; tc++) {
			N = Integer.parseInt(br.readLine());

			coins = new Coin[N + 1];
			sum = 0;

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				amount = Integer.parseInt(st.nextToken());
				cnt = Integer.parseInt(st.nextToken());

				coins[i + 1] = new Coin(amount, cnt);
				sum += amount * cnt;

			}

			if ((sum & 1) == 1) {
				sb.append(0).append('\n');
				continue;
			}

			boolean[][] dp = new boolean[N + 1][sum + 1];
			sum /= 2;
			dp[0][0] = true;

			for (int i = 1; i < N + 1; i++) {
				Coin curr = coins[i];
				for (int j = 0; j <= sum; j++) {
					if (dp[i - 1][j]) {
						for (int k = 0; k < curr.cnt + 1; k++) {
							int temp = j + k * curr.amount;
							if (temp <= sum) {
								dp[i][temp] = true;
							}
						}
					}
				}
			}

			if (dp[N][sum]) {
				sb.append(1).append('\n');
			} else {
				sb.append(0).append('\n');
			}
		}
		System.out.println(sb);
	}
}