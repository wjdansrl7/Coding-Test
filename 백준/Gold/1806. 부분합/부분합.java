
import java.io.*;
import java.util.*;

/**
 *packageName    : _250703
 * fileName       : BOJ_G4_1806_부분합
 * author         : moongi
 * date           : 7/5/25
 * description    :
 */
public class Main {
	static int N, S;
	static int[] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());

		arr = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int ans = Integer.MAX_VALUE;
		int left = 0;
		long sum = 0;

		for (int right = 0; right < N; right++) {
			sum += arr[right];

			while (sum >= S) {
				ans = Math.min(ans, right - left + 1);
				sum -= arr[left++];
			}
		}

		System.out.println(ans == Integer.MAX_VALUE ? 0 : ans);
		
	}
}
