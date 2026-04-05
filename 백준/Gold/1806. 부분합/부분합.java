
import java.io.*;
import java.util.*;
/**
 *packageName    : _260405
 * fileName       : BOJ_G4_1806_부분합
 * author         : moongi
 * date           : 4/5/26
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int S = Integer.parseInt(st.nextToken());

		int[] arr = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int start = 0;
		int ans = Integer.MAX_VALUE;
		long partial = 0;

		for (int end = 0; end < N; end++) {

			partial += arr[end];

			while (partial >= S) {
				ans = Math.min(ans, end - start + 1);
				partial -= arr[start++];
			}
		}

		System.out.println(ans == Integer.MAX_VALUE ? 0 : ans);
	}
}
