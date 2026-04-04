
import java.util.*;
import java.io.*;
/**
 *packageName    : _260404
 * fileName       : BOJ_S2_1406_에디터_Ver2
 * author         : moongi
 * date           : 4/5/26
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		String str = br.readLine();

		Stack<Character> lStack = new Stack<>();
		Stack<Character> rStack = new Stack<>();

		for (int i = 0; i < str.length(); i++) {
			lStack.push(str.charAt(i));
		}

		int M = Integer.parseInt(br.readLine());

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			switch (st.nextToken()) {
				case "L":
					if (!lStack.isEmpty())
						rStack.push(lStack.pop());
					break;
				case "D":
					if (!rStack.isEmpty())
						lStack.push(rStack.pop());
					break;
				case "B":
					if (!lStack.isEmpty())
						lStack.pop();
					break;
				case "P":
					lStack.push(st.nextToken().charAt(0));
					break;
			}
		}

		while (!lStack.isEmpty()) {
			rStack.push(lStack.pop());
		}

		while (!rStack.isEmpty()) {
			sb.append(rStack.pop());
		}
		System.out.println(sb);
	}
}