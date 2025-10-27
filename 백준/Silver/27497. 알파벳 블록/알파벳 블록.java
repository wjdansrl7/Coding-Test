
import java.util.*;
import java.io.*;
/**
 *packageName    : _251027
 * fileName       : BOJ_S2_27497_알파벳블록
 * author         : moongi
 * date           : 10/27/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		int idx = 0;

		ArrayDeque<Character> q = new ArrayDeque<>();
		ArrayDeque<Integer> orders = new ArrayDeque<>();

		orders.offer(0);
		for (int i = 0; i < N; i++) {
			String[] str = br.readLine().split(" ");

			int cmd = str[0].charAt(0) - '0';
			if (cmd == 1) {
				q.offer(str[1].charAt(0));
				orders.offer(1);
			} else if (cmd == 2) {
				q.push(str[1].charAt(0));
				orders.offer(2);
			} else {
				if (!orders.isEmpty()) idx = orders.pollLast();
				else idx = 0;
				
				if (idx == 1) {
					q.pollLast();
				} else if (idx == 2) {
					q.pop();
				}
			}
		}

		if (q.isEmpty()) {
			sb.append(0);
		} else {
			while (!q.isEmpty()) {
				sb.append(q.poll());
			}
		}
		System.out.println(sb);

	}
}