
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());

		Stack<Integer> stk = new Stack<>();
		int curr;

		boolean flag = false;
		int idx = 1;
		for (int i = 0; i < N; i++) {

			curr = Integer.parseInt(br.readLine());
			flag = false;

			while (idx <= curr) {
				flag = true;
				stk.push(idx++);
				sb.append("+\n");
			}

			while (!stk.isEmpty() && stk.peek() >= curr) {
				flag = true;
				stk.pop();
				sb.append("-\n");
			}

			if (!flag) break;

		}

		if(!flag) System.out.println("NO");
		else System.out.println(sb);

	}
}