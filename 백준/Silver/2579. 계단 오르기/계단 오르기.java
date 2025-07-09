
import java.io.*;
import java.util.*;

/**
 *packageName    : _250708
 * fileName       : BOJ_S3_2579_계단오르기
 * author         : moongi
 * date           : 7/8/25
 * description    :
 *
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N+1];

		for (int i = 1; i < N + 1; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}

		int[] dp = new int[N + 1];

		dp[1] = arr[1];

		if (N >= 2) {
			dp[2] = arr[1] + arr[2];
		}

		for (int i = 3; i < N + 1; i++) {

			dp[i] = Math.max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
		}

		System.out.println(dp[N]);
	}
}