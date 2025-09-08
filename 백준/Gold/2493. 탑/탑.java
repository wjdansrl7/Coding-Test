
import java.util.*;
import java.io.*;
/**
 *packageName    : _250908
 * fileName       : BOJ_G5_2493_탑
 * author         : moongi
 * date           : 9/8/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];

		ArrayDeque<int[]> stk = new ArrayDeque<>();

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		StringBuilder sb = new StringBuilder();

		stk.push(new int[] {1, arr[0]}); // 현재 가장 높은 높이
		sb.append(0).append(" ");

		for (int i = 1; i < N; i++) {

			int curr = arr[i];

			while(!stk.isEmpty() && stk.peek()[1] < curr) {
				stk.pop();
			}

			if (stk.isEmpty()) {
				sb.append(0).append(" ");
			} else {
				sb.append(stk.peek()[0]).append(" ");
			}

			stk.push(new int[] {i + 1, curr});
		}

		System.out.println(sb);
		
	}
}