
import java.util.*;
import java.io.*;
/**
 *packageName    : _250708
 * fileName       : BOJ_S2_1912_연속합
 * author         : moongi
 * date           : 7/8/25
 * description    :
 */
public class Main {
	static int[] sum;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());

		int[] arr = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		sum = new int[N];
		sum[0] = arr[0];

		int ans = sum[0];
		for (int i = 1; i < N; i++) {
			sum[i] = Math.max(arr[i] + sum[i - 1], arr[i]);
			ans = Math.max(ans, sum[i]);
		}

		System.out.println(ans);
	}
}