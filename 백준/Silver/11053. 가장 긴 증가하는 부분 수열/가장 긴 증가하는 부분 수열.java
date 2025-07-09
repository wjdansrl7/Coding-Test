
import java.io.*;
import java.util.*;
/**
 *packageName    : _250709
 * fileName       : BOJ_S2_11053_가장긴증가하는부분수열
 * author         : moongi
 * date           : 7/9/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		int[] dp = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		for (int i = 0; i < N; i++) {
			int max = 0;
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j]) {
					if (max < dp[j]) max = dp[j];
				}
			}
			dp[i] = max + 1;
		}

		Arrays.sort(dp);
		System.out.println(dp[N-1]);
	}
}