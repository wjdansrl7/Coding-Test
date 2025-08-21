import java.util.*;
import java.io.*;
/**
 *packageName    : _250821
 * fileName       : BOJ_G3_13325_이진트리
 * author         : moongi
 * date           : 8/21/25
 * description    :
 */
public class Main {
	static int size, ans;
	static int[] nodes;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int K = Integer.parseInt(br.readLine());
		size = (int)Math.pow(2, K + 1) - 1;
		nodes = new int[size + 1]; // 트리의 개수

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 2; i <= size; i++) {
			nodes[i] = Integer.parseInt(st.nextToken());
		}

		ans = 0;

		dfs(1);

		System.out.println(ans);

	}

	static int dfs(int start) {

		// 리프노드의 값을 더해주고 반환한다.
		if (start * 2 >= size) {
			ans += nodes[start];
			return nodes[start];
		}

		int left = dfs(start * 2);
		int right = dfs(start * 2 + 1);

		// 현재 노드의 값과 자식 노드의 차이를 더해준다.
		// => 왼쪽 자식, 오른쪽 자식 중 작은 값을 증가시켜 값은 값으로 만든다는 것.
		ans += nodes[start] + Math.abs(left - right);
		return nodes[start] + Math.max(left, right);
	}
}