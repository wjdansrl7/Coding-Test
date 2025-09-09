import java.util.*;
import java.io.*;

/**
 *packageName    : _250909
 * fileName       : BOJ_S2_1654_랜선자르기
 * author         : moongi
 * date           : 9/9/25
 * description    :
 */
public class Main {
	static int K, N;
	static int[] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		K = Integer.parseInt(st.nextToken()); // <= 10,000
		N = Integer.parseInt(st.nextToken()); // <= 1,000,000

		arr = new int[K];
		long lo = 1, hi = 0;
		long ans = 0;
		for (int i = 0; i < K; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			hi = arr[i] > hi ? arr[i] : hi;
		}

		while (lo <= hi) {

			long mid = (lo + hi) >> 1;

			long sum =  0;
			for (int i = 0; i < K; i++) {
				sum += arr[i] / mid;
			}

			if(sum >= N) {
				// 길이를 더 크게 해보자.
				lo = mid + 1;
				ans = mid;
			} else {
				// 길이를 더 작게 만들어야 한다.
				hi = mid - 1;
			}
		}

		System.out.println(ans);
	}
}