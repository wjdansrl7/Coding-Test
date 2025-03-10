
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());

		int[] arr = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		int left = 1, right = arr[N - 1];
		int res = 0;

		while (left <= right) {
			int mid = (left + right) / 2;
			int cnt = 0;
			
			for (int i = 0; i < N; i++) {
				cnt += arr[i] / mid;
			}

			if (cnt >= M) {
				left = mid + 1;
				res = mid;
			} else {
				right = mid - 1;
			}
		}

		System.out.println(res);
	}
}