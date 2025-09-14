
import java.util.*;
import java.io.*;
/**
 *packageName    : _250910
 * fileName       : BOJ_P5_14003_가장긴증가하는부분수열5
 * author         : moongi
 * date           : 9/10/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		int[] dp = new int[N]; // 각 길이별 최소 꼬리값(tails)
		int[] parent = new int[N]; // LIS 복원용: 이전 인덱스
		int[] idxAtLen = new int[N]; // 길이 k(1-based)의 마지막 원소의 "원본 인덱스"

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.fill(parent, -1);

		dp[0] = arr[0];
		idxAtLen[0] = 0; // 길이 1의 마지막 인덱스는 0번
		int len = 1;

		for (int i = 1; i < N; i++) {
			int key = arr[i];

			if (dp[len - 1] < arr[i]) {
				// 새로 길이를 늘리는 경우 (pos = len)
				parent[i] = idxAtLen[len - 1];
				dp[len] = key;
				idxAtLen[len] = i;
				len++;
			} else {
				// 대치를 하는 과정에서 탐색하는 값보다 큰 가장 가까운 원소를 찾는데 쓰이는 것
				// lowerBound: dp[pos] >= key
				int start = 0, end = len;

				while (start < end) {
					int mid = (start + end) >> 1;

					if (dp[mid] >= key)
						end = mid;
					else
						start = mid + 1;
				}
				int pos = end;

				dp[pos] = key;
				idxAtLen[pos] = i;
				if (pos > 0) parent[i] = idxAtLen[pos - 1];
				// pos == 0이면 이전 원소가 없으므로 parent[i]는 기본값 -1 유지
			}
		}

		// 역추적
		int[] lis = new int[len];
		int cur = idxAtLen[len - 1];
		for (int k = len - 1; k >= 0; k--) {
			lis[k] = arr[cur];
			cur = parent[cur];
		}

		sb.append(len).append('\n');
		for (int i = 0; i < len; i++) {
			sb.append(lis[i]).append(' ');
		}
		System.out.println(sb);
		
	}
}
