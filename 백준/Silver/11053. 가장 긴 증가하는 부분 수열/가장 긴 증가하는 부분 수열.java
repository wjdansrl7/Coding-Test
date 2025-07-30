import java.io.*;
import java.util.*;

/**
 *packageName    : _250730
 * fileName       : BOJ_S2_11053_가장긴증가하는부분수열
 * author         : moongi
 * date           : 7/30/25
 * description    :
 */
public class Main {
	static int[] dp;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		dp = new int[N];
		int LIS = 0;

		for (int i = 0; i < N; i++) {
			int idx = lowerBound(arr[i], 0, LIS, LIS + 1); // num, start, end, size

			if (idx == -1) {
				dp[LIS++] = arr[i];
			} else {
				dp[idx] = arr[i];
			}
		}

		System.out.println(LIS);
		
	}

	static int lowerBound(int num, int start, int end, int size) {
		int res = 0;

		while (start <= end) {

			int mid = (start + end) >> 1;

			if (num <= dp[mid]) {
				res = mid;
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}

		if (start == size) return -1;
		else return res;

	}
}