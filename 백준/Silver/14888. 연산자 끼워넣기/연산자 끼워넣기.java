
import java.util.*;
import java.io.*;

/**
 *packageName    : _260302
 * fileName       : BOJ_S1_14888_연삱끼워넣기
 * author         : moongi
 * date           : 3/2/26
 * description    :
 */
public class Main {
	static int max, min;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		max = Integer.MIN_VALUE; min = Integer.MAX_VALUE;

		int N = Integer.parseInt(br.readLine());
		int[] operands = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			operands[i] = Integer.parseInt(st.nextToken());
		}

		// + - x /
		int[] oeprator = new int[4];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < 4; i++) {
			oeprator[i] = Integer.parseInt(st.nextToken());
		}

		comb(1, operands, oeprator, operands[0]);

		sb.append(max).append('\n');
		sb.append(min).append('\n');
		System.out.println(sb);


	}

	static void comb(int cnt, int[] operands, int[] operator, int result) {

		if (cnt == operands.length && operator[0] == 0 && operator[1] == 0 && operator[2] == 0 && operator[3] == 0) {
			max = result > max ? result : max;
			min = min > result ? result : min;

			return;
		}

		for (int i = cnt; i < operands.length; i++) {

			if (operator[0] > 0) {
				operator[0]--;
				comb(i+1, operands, operator, result + operands[i]);
				operator[0]++;
			}
			if (operator[1] > 0) {
				operator[1]--;
				comb(i+1, operands, operator, result - operands[i]);
				operator[1]++;
			}
			if (operator[2] > 0) {
				operator[2]--;
				comb(i+1, operands, operator, result * operands[i]);
				operator[2]++;
			}
			if (operator[3] > 0) {
				operator[3]--;
				comb(i+1, operands, operator, result / operands[i]);
				operator[3]++;
			}
		}
	}
}
