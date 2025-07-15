import java.util.*;
import java.io.*;
/**
 *packageName    : _250715
 * fileName       : BOJ_G3_2473_세용액
 * author         : moongi
 * date           : 7/15/25
 * description    :
 */
public class Main {
	static int N;
	static long[] arr, res;
	static Long ans;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		arr = new long[N];
		ans = Long.MAX_VALUE;
		res = new long[3];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		for (int i = 0; i < N - 2; i++) {
			solve(i);
		}

		Arrays.sort(res);

		for (int i = 0; i < 3; i++) {
			sb.append(res[i]).append(" ");
		}

		System.out.println(sb);
	}

	static void solve(int target) {

		int start = target + 1;
		int end = N - 1;

		while (start < end) {

			long sum = arr[start] + arr[end] + arr[target];
			long absSum = Math.abs(sum);

			if (absSum < ans) {
				ans = absSum;

				res[0] = arr[start];
				res[1] = arr[end];
				res[2] = arr[target];
			}

			if (sum >= 0) {
				end--;
			} else {
				start++;
			}
		}
	}
}