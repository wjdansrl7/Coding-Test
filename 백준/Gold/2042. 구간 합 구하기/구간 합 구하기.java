import java.io.*;
import java.util.*;
/**
 *packageName    : _250805
 * fileName       : BOJ_G1_2042_구간합구하기
 * author         : moongi
 * date           : 8/5/25
 * description    :
 */
public class Main {
	static int N, M, K;
	static long[] arr, tree;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		arr = new long[N];
		tree = new long[N * 4];

		for (int i = 0; i < N; i++) {
			arr[i] = Long.parseLong(br.readLine());
		}

		init(0, N - 1, 1); // start, end, root node

		for (int i = 0; i < M + K; i++) {
			st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			long c = Long.parseLong(st.nextToken());

			if (a == 1) {
				// update
				update(0, N - 1, 1, b - 1, c - arr[b - 1]);
                arr[b - 1] = c;
			} else {
				// 구간 합 구하기
				sb.append(sum(0, N - 1, 1, b-1, c-1)).append('\n');

			}
		}

		System.out.println(sb);
	}

	static long init(int start, int end, int node) {

		if (start == end) return tree[node] = arr[start];
		int mid = (start + end) >> 1;
		return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
	}

	static long sum(int start, int end, int node, int left, long right) {
		// 범위 밖에 있는 경우
		if (left > end || right < start) return 0;
		// 범위 안에 있는 경우
		if (left <= start && end <= right) return tree[node];

		int mid = (start + end) >> 1;
		return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);

	}

	static void update(int start, int end, int node, int index, long dif) {

		if (index < start || index > end) return;

		tree[node] += dif;
		if (start == end) return;
		int mid = (start + end) >> 1;
		update(start, mid, node * 2, index, dif);;
		update(mid + 1, end, node * 2 + 1, index, dif);
	}

}