import java.util.*;
import java.io.*;
/**
 *packageName    : _250708
 * fileName       : BOJ_S3_11726_2n타일링
 * author         : moongi
 * date           : 7/8/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());

		int[] dp = new int[1001];
		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3; i < N + 1; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
		}

		sb.append(dp[N]);
		System.out.println(sb);
	}
}