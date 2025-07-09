

import java.io.*;
import java.util.*;

/**
 *packageName    : _250709
 * fileName       : BOJ_G2_12738_가장긴증가하는부분수열3
 * author         : moongi
 * date           : 7/9/25
 * description    :
 */
public class Main {
	static int[] dp;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		int[] arr = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		dp = new int[N];
		Arrays.fill(dp, Integer.MIN_VALUE);
		int LIS = 0;

		for (int i = 0; i < N; i++) {

			int idx = binarySearch(arr[i], 0, LIS, LIS + 1);

			// 찾지 못한 경우
			if (idx == -1) {
				// 가장 마지막 위치에 원소를 삽입하고 LIS의 길이를 늘린다.
				dp[LIS++] = arr[i];
			} else {
				dp[idx] = arr[i];
			}
		}

		System.out.println(LIS);

	}

	static int binarySearch(int num, int start, int end, int size) {

		int res = 0;
		while (start <= end) {
			int mid = (start + end) / 2;

			// 만일 현재 선택된 원소가 해당 원소보다 작거나 같다면, 앞 부분을 탐색한다.
			if (num <= dp[mid]) {
				res = mid;
				end = mid - 1;
			}
			// 만일 현재 선택된 원소가 해당 원소보다 크다면, 뒷 부분을 탐색한다.
			else {
				start = mid + 1;
			}
		}

		// dp테이블에서 삽입될 위치를 찾지 못한 경우(즉, 모든 수들보다 큰 경우)
		if (start == size) {
			return -1;
		} else {
			return res;
		}
	}
}