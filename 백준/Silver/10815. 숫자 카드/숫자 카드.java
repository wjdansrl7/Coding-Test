import java.util.*;
import java.io.*;
/**
 *packageName    : _250518
 * fileName       : BOJ_S5_10815_숫자카드
 * author         : moongi
 * date           : 5/18/25
 * description    :
 */
public class Main {
	static int N;
	static int[] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		arr = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		int M = Integer.parseInt(br.readLine());

		int num = 0;
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			num = Integer.parseInt(st.nextToken());

			sb.append(binarySearch(num)).append(" ");
		}

		System.out.println(sb);
	}

	static int binarySearch(int num) {

		int start = 0, end = N-1;

		while (start <= end) {

			int mid = (start + end) >> 1;

			if (arr[mid] == num) return 1;
			else if (arr[mid] > num) end = mid - 1;
			else start = mid + 1;
		}

		return 0;

	}
}