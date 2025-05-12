
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N+1];
		int[] dp = new int[N + 1];
		Set<Integer>[] lists = new TreeSet[N + 1];

		for (int i = 0; i < N + 1; i++) {
			lists[i] = new TreeSet<>();
		}

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i < N + 1; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			dp[i] = 1;
			lists[i].add(arr[i]);
		}

		for (int i = 1; i < N + 1; i++) {

			int max = 0;
			int idx = -1;
			for (int j = 1; j < i; j++) {
				if (i == j) continue;

				if (arr[i] <= arr[j]) continue;

				// 현재 순회 중에 자신보다 값이 작으면서 부분 수열의 개수가 가장 큰 경우
				if (dp[j] > max) {
					max = dp[j];
					idx = j;
				}
			}

			if (idx == -1) continue;

			for(Integer k : lists[idx]) {
				lists[i].add(k);
			}

			dp[i] = lists[i].size();
		}

		int max = 0;
		int idx = -1;
		for (int i = 1; i < N + 1; i++) {
			if (lists[i].size() > max) {
				idx = i;
				max = lists[i].size();
			}
		}

		StringBuilder sb = new StringBuilder();

		if (idx != -1) {
			sb.append(max + "\n");

			for(Integer l : lists[idx])
				sb.append(l + " ");
		}

		System.out.println(sb);

	}
}