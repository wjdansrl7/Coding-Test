
import java.util.*;
import java.io.*;
/**
 *packageName    : _250701
 * fileName       : BOJ_
 * author         : moongi
 * date           : 7/1/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());

		ArrayDeque<Integer> q = new ArrayDeque<>();
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());

			String cmd = st.nextToken();

			switch (cmd) {
				case "push": {
					q.offer(Integer.parseInt(st.nextToken()));
					break;
				}
				case "pop": {
					if (!q.isEmpty()) {
						sb.append(q.pop()).append('\n');
					} else {
						sb.append(-1).append('\n');
					}
					break;
				}
				case "size": {
					sb.append(q.size()).append('\n');
					break;
				}
				case "empty": {
					if (q.isEmpty()) {
						sb.append(1).append('\n');
					} else {
						sb.append(0).append('\n');
					}
					break;
				}
				case "front": {
					if (!q.isEmpty()) {
						sb.append(q.peek()).append('\n');
					} else {
						sb.append(-1).append('\n');
					}
					break;
				}
				case "back": {
					if (!q.isEmpty()) {
						sb.append(q.peekLast()).append('\n');
					} else {
						sb.append(-1).append('\n');
					}
					break;
				}
			}
		}

		System.out.println(sb);
	}
}