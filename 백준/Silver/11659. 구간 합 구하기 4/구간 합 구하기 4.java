
import java.io.*;
import java.util.*;
/**
 *packageName    : _260404
 * fileName       : BOJ_S3_11659_구간합구하기4
 * author         : moongi
 * date           : 4/4/26
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[] arr = new int[N];
		int[] sum = new int[N + 1];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());

		sum[1] = arr[0];
		for (int i = 2; i < N + 1; i++) sum[i] = sum[i - 1] + arr[i - 1];

		int start = 0, end = 0;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());

			sb.append(sum[end] - sum[start - 1]).append('\n');
		}

		System.out.println(sb);
	}
}
