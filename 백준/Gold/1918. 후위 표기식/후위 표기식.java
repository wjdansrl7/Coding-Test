import java.util.*;
import java.io.*;

/**
 *packageName    : _250430
 * fileName       : BOJ_G2_1918_후위표기식
 * author         : moongi
 * date           : 4/30/25
 * description    : https://moonsbeen.tistory.com/133
 *
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		String str = br.readLine();

		Stack<Character> op = new Stack<>();

		for (int i = 0; i < str.length(); i++) {

			char curr = str.charAt(i);

			if (curr >= 'A' && curr <= 'Z') {
				sb.append(curr);
			} else {
				if (curr == '(') {
					op.push(curr);
				} else if (curr == ')') {
					while (!op.isEmpty() && op.peek() != '(') {
						sb.append(op.pop());
					}
					// '(' 에 대해 빼준다.
					if (!op.isEmpty())
						op.pop();
				} else { // + - / * 연산자 일 경우
					while (!op.isEmpty() && compareOperand(op.peek()) >= compareOperand(curr)) {
						sb.append(op.pop());
					}
					op.push(curr);
					
				}
			}
		}

		while (!op.isEmpty()) {
			sb.append(op.pop());
		}
		System.out.println(sb);
		
	}

	static int compareOperand(char op) {
		if (op == '*' || op == '/') return 2;
		else if (op == '+' || op == '-') return 1;
		else return 0;
	}
}