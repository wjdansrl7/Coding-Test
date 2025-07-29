import java.io.*;
import java.util.*;

/**
 *packageName    : _250729
 * fileName       : BOJ_S4_9012
 * author         : moongi
 * date           : 7/29/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		label: for (int tc = 0; tc < T; tc++) {
			String str = br.readLine();

			ArrayDeque<Character> q = new ArrayDeque<>();
			for (int i = 0; i < str.length(); i++) {

				if (str.charAt(i) == '(') {
					q.offer('(');
				} else {

					if (q.isEmpty()) {
						sb.append("NO\n");
						continue label;
					} else {
						q.pollLast();
					}
				}
			}

			if (!q.isEmpty()) {
				sb.append("NO\n");
			} else {
				sb.append("YES\n");
			}
		}
		System.out.println(sb);
	}
}