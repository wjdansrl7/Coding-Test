import java.util.*;
import java.io.*;
/**
 *packageName    : _250813
 * fileName       : BOJ_G3_13325_이진트리
 * author         : moongi
 * date           : 8/13/25
 * description    :
 * // 2 2 3 3 3 3
 */
public class Main {
	static int size, ans;
	static int[] tree;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int K = Integer.parseInt(br.readLine());
		ans = 0;

		// 트리 노드의 개수
		size = (int) Math.pow(2, K + 1) - 1; // 7

		tree = new int[size + 1];

		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 2; i <= size; i++) {
			tree[i] = Integer.parseInt(st.nextToken());
		}

		dfs(1);
		System.out.println(ans);

	}

	static int dfs(int node) {

		if (node * 2 >= size) {
			// 리프노드의 값을 더해주고 반환한다.
			ans += tree[node];
			return tree[node];
		}

		int left = dfs(node * 2);
		int right = dfs(node * 2 + 1);

		ans += tree[node] + Math.abs(left - right);
		return tree[node] + Math.max(left, right);

	}


}