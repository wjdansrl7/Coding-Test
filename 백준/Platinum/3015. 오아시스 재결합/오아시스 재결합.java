
import java.util.*;
import java.io.*;

public class Main {
	static class Node {
		int height;
		int cnt;

		public Node(int height, int cnt) {
			this.height = height;
			this.cnt = cnt;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		ArrayDeque<Node> stk = new ArrayDeque<>();
		long res = 0;

		for (int i = 0; i < N; i++) {
			int height = Integer.parseInt(br.readLine());
			Node cur = new Node(height, 1);

			while (!stk.isEmpty() && stk.peek().height <= height) {
				Node top = stk.pop();
				res += top.cnt;

				// 자신과 키가 동일한 사람은 stk에서 제거하므로 이후 자신보다 큰 사람이 stk에 들어올 경우, 해당하는 사람의 수만큼을 더해주기 위해
				if (top.height == height) {
					cur.cnt += top.cnt;
				}
			}

			// 자신과 pair 되는 사람
			if (!stk.isEmpty()) {
				res++;
			}

			stk.push(cur);
		}

		System.out.println(res);
	}
}
