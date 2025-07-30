import java.io.*;
import java.util.*;

/**
 *packageName    : _250730
 * fileName       : BOJ_S2_1654_랜선자르기
 * author         : moongi
 * date           : 7/30/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int K = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());

		long[] arr = new long[K];
		long start = 1, end = 0;

		for (int i = 0; i < K; i++) {
			arr[i] = Long.parseLong(br.readLine());

			if (end < arr[i]) end = arr[i];
		}

		long ans = 0;
		while (start <= end) {

			long mid = (start + end) >> 1;

			long cnt = 0;
			for (int i = 0; i < K; i++) {
				cnt += arr[i] / mid;
			}

			if (cnt >= N) {
				ans = mid;
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}

		System.out.println(ans);
	}
}