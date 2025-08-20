import java.io.*;
import java.util.*;

/**
 *packageName    : _250820
 * fileName       : BOJ_G4_1662_압축
 * author         : moongi
 * date           : 8/20/25
 * description    :
 *
 * 3(3(3(2(2)2(2))))
 *
 * 2 * 2
 *
 *
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		// 압축된 문자열 S
		String str = br.readLine();
		ArrayDeque<Integer> stk = new ArrayDeque<>();
		for (int i = 0; i < str.length(); i++) {

			char c = str.charAt(i);
			if (c == '(') {
				stk.push(-1);
			} else if (c == ')') {
				int sum = 0;

				while (!stk.isEmpty() && stk.peek() != -1) {
					sum += stk.pop();
				}

				stk.pop();

				if (!stk.isEmpty() && stk.peek() >= 0 && stk.peek() <= 9) {
					stk.push(sum * stk.pop());
				} else {
					stk.push(sum);
				}

			} else {

				if (i + 1 < str.length() && str.charAt(i + 1) == '(') {
					stk.push(c - '0');
				} else {
					stk.push(1);
				}
			}
		}

		int ans = 0;
        StringBuilder sb = new StringBuilder();
        
		while(!stk.isEmpty())
			ans += stk.poll();
        
        sb.append(ans);
		System.out.println(sb);
	}
}