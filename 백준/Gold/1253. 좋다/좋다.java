
import java.util.*;
import java.io.*;

/**
 *packageName    : _250624
 * fileName       : BOJ_G4_1253_좋다
 * author         : moongi
 * date           : 6/24/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];

		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		int cnt = 0;

		for (int i = 0; i < N; i++) {
			int start = 0;
			int end = N - 1;

			while (true) {
				if (start == i) start++;
				else if (end == i) end--;

				if (start >= end) break;

				if (arr[start] + arr[end] > arr[i]) end--;
				else if (arr[start] + arr[end] < arr[i]) start++;
				else {
					cnt++;
					break;
				}
			}
		}

		System.out.println(cnt);
	}
}
