
import java.util.*;
import java.io.*;
/**
 *packageName    : _250627
 * fileName       : BOJ_G4_1806
 * author         : moongi
 * date           : 6/27/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(st.nextToken());
		int S = Integer.parseInt(st.nextToken());

		int[] arr = new int[N];

		// 길이를 이분 탐색한다.

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int res = 100_001;
		int left = 0, right = N;

		while (left <= right) {

			int mid = (left + right) >> 1;

			int sum = 0;
			for (int i = 0; i < mid; i++) {
				sum += arr[i];
			}

			if (sum >= S) {
				right = mid - 1;
				if(res > mid) res = mid;
				continue;
			}

			boolean flag = false;
			for (int i = mid, j = 0; i < N; i++, j++) {
				sum -= arr[j];
				sum += arr[i];

				if (sum >= S) {
					right = mid - 1;
					if(res > mid) res = mid;
					flag = true;
					break;
				}
			}

			if (!flag) {
				left = mid + 1;
			}
		}

		if (res == 100_001) res = 0;

		sb.append(res);
		System.out.println(res);
	}
}
