import java.util.*;
import java.io.*;
/**
 *packageName    : _250823
 * fileName       : BOJ_B2_13458_시험감독
 * author         : moongi
 * date           : 8/23/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		int[] arr = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		st = new StringTokenizer(br.readLine());
		int B = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());

		long ans = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] <= B) {
				ans++;
				continue;
			} else {
				ans++;
				arr[i] -= B;
				
				ans += arr[i] / C;
				if (arr[i] % C != 0) {
					ans++;
				}
			}
		}

		System.out.println(ans);
	}
}