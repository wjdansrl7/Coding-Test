import java.util.*;
import java.io.*;
/**
 *packageName    : _260217
 * fileName       : BOJ_S2_1912_연속합
 * author         : moongi
 * date           : 2/17/26
 * description    :
 * 10, -4, 3, 1, 5, 6, -35, 12, 21, -1
 * 10 6 9 10 15 21 -14 -2 19 18
 *
 * 2 1 -4 3 4 -4 6 5 -5 1
 * 2 3 -1 2 6 2 8 13 8 9
 *
 * binary search
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());

		int[] arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int[] sum = new int[N];

		sum[0] = arr[0];
		int res = sum[0];

		for (int i = 1; i < N; i++) {
			sum[i] = Math.max(arr[i] + sum[i-1], arr[i]);
			res = Math.max(res, sum[i]);
		}

		System.out.println(res);
	}
}
