import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String str = br.readLine();

		Stack<Character> stk = new Stack<>();
		int res = 0;
		int val = 1;

		for (int i = 0; i < str.length(); i++) {
			char curr = str.charAt(i);

			if (curr == '(') {
				stk.push(curr);
				val *= 2;
			} else if (curr == '[') {
				stk.push(curr);
				val *= 3;
			} else if (curr == ')') {
				if (stk.isEmpty() || stk.peek() != '(') {
					res = 0;
					break;
				} else if (str.charAt(i - 1) == '(') {
					res += val;
				}
				stk.pop();
				val /= 2;
			} else if (str.charAt(i) == ']'){
				if (stk.isEmpty() || stk.peek() != '[') {
					res = 0;
					break;
				} else if (str.charAt(i - 1) == '[') {
					res += val;
				}
				stk.pop();
				val /= 3;
			}
		}

		if (!stk.isEmpty()) res = 0;

		sb.append(res);
		System.out.println(sb);
	}
}