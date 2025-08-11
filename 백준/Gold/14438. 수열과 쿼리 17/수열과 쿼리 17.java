
import java.util.*;
import java.io.*;
/**
 *packageName    : _250811
 * fileName       : BOJ_G1_14438_수열과쿼리17
 * author         : moongi
 * date           : 8/11/25
 * description    :
 *
 * 해당 구간에서의 최솟값을 구한다.
 * 세그먼트 트리의 응용
 */
public class Main {
	static int N, M;
	static int[] arr, tree;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		tree = new int[N * 4];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		init(0, N - 1, 1);

		M = Integer.parseInt(br.readLine());

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			if (a == 1) {
				update(0, N - 1, 1, b - 1, c);
				arr[b-1] = c;

			} else {
				sb.append(minValue(0, N - 1, 1, b - 1, c - 1)).append('\n');
			}

		}
		System.out.println(sb);
	}
	
	static int init(int start, int end, int node) {

		if (start == end) return tree[node] = arr[start];

		int mid = (start + end) >> 1;
		return tree[node] = Math.min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
	}

	static int minValue(int start, int end, int node, int left, int right) {

		if (start > right || end < left) return Integer.MAX_VALUE;
		if (left <= start && end <= right) return tree[node];

		int mid = (start + end) >> 1;
		return Math.min(minValue(start, mid, node * 2, left, right), minValue(mid + 1, end, node * 2 + 1, left, right));
	}

	// 바뀌기 전 갑이 최솟값이었다면 바뀌는 수가 더 크다면 바꾸지 않는 거 였다.
	static void update(int start, int end, int node, int index, int dif) {

		if (index < start || index > end) return;
		// 5 -> 2

		if (start == end) {
			tree[node] = dif;
			return;
		}

		int mid = (start + end) >> 1;
		if(index <= mid) update(start, mid, node * 2, index, dif);
		else update(mid + 1, end, node * 2 + 1, index, dif);

		tree[node] = Math.min(tree[node * 2], tree[node * 2 + 1]);
	}
}