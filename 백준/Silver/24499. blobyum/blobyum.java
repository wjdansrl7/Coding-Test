
import java.util.*;
import java.io.*;

/**
 *packageName    : _250504
 * fileName       : BOJ_S4_24499_blobyum
 * author         : moongi
 * date           : 5/4/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());

		int K = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());

		int[] arr = new int[K];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < K; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int res = 0;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += arr[i];
		}

		res = sum;

		for (int i = 0; i < K; i++) {
			sum -= arr[i];
			sum += arr[(i + N) % K];

			res = sum > res ? sum : res;
		}

		sb.append(res);
		System.out.println(sb);
		
	}
}