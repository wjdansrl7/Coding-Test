
import java.io.*;
import java.util.*;

/**
 *packageName    : _250729
 * fileName       : BOJ_S4_18258_큐2
 * author         : moongi
 * date           : 7/29/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		ArrayDeque<Integer> q = new ArrayDeque<>();

		while (N-- > 0) {
			st = new StringTokenizer(br.readLine());

			String cmd = st.nextToken();

			if (cmd.equals("push")) {

				solve(cmd, Integer.parseInt(st.nextToken()), q);
			} else {

				sb.append(solve(cmd, -1, q)).append('\n');
			}

		}

		System.out.println(sb);

	}

	static int solve(String cmd, int val, ArrayDeque<Integer> q) {

		if (cmd.equals("push")) {
			q.offer(val);
		} else if (cmd.equals("pop")) {
			if (q.isEmpty()) {
				return -1;
			} else {
				return q.poll();
			}
		} else if (cmd.equals("size")) {
			return q.size();
		} else if (cmd.equals("empty")) {
			if (q.isEmpty())
				return 1;
			else
				return 0;
		} else if (cmd.equals("front")) {
			if (q.isEmpty()) return -1;
			else return q.peek();
		} else {
			if (q.isEmpty()) return -1;
			else return q.peekLast();
		}

		return 999;
	}
}