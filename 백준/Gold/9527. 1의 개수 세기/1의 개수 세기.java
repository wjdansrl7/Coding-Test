
import java.util.*;
import java.io.*;

public class Main {
	static long N, M;
	static long[] dp;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Long.parseLong(st.nextToken());
		M = Long.parseLong(st.nextToken());
		dp = new long[55];

		setDp();

		System.out.println(calOne(M) - calOne(N - 1));
	}

	static long calOne(long N) {
		long count = N & 1;
		// N보다 작은 2^n의 최대값
		int size = (int)(Math.log(N) / Math.log(2));
		// 비트마스킹을 이용한 1의 개수 계산 진행
		// DP[i-1] : 000 ~ 111 개수
		// N - (1L << i) : 지정된 1이 반복 사용될 개수
		// + 1 : 1000...
		for (int i = size; i > 0; i--) {
			if ((N & (1L << i)) != 0L) {
				count += dp[i - 1] + (N - (1L << i) + 1);
				N -= (1L << i); // 비트 이동시키기
			}
		}
		return count; // 1의 개수 반환
	}

	static void setDp() {
		dp[0] = 1;

		for (int i = 1; i < 55; i++) {
			dp[i] = (dp[i - 1] << 1) + (1L << i);
		}
	}
}