import java.io.*;
import java.util.*;

/**
 *packageName    : _250729
 * fileName       : BOJ_S4_10828_스택
 * author         : moongi
 * date           : 7/29/25
 * description    :
 */
public class Main {
	static Stack<Integer> stk;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		stk = new Stack<>();

		for (int cmd = 0; cmd < N; cmd++) {

			st = new StringTokenizer(br.readLine());

			String str = st.nextToken();

			if (str.equals("push")) solve(str, Integer.parseInt(st.nextToken()));
			else sb.append(solve(str, -1)).append('\n');
			
		}

		System.out.println(sb);
	}

	static int solve(String str, int val) {
		if (str.equals("push")) {
			
			stk.push(val);
		} else if (str.equals("pop")) {
			
			if (stk.isEmpty()) return -1;
			else return stk.pop();
		} else if (str.equals("size")) {
			
			return stk.size();
		} else if (str.equals("empty")) {
			
			if (stk.isEmpty()) return 1;
			else return 0;
		} else {
			
			if (stk.isEmpty()) return -1;
			else return stk.peek();
		}

		return 999;
	}
}