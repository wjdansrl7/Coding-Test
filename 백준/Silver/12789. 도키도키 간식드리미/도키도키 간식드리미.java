
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());
		Stack<Integer> ord = new Stack<>();
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		for (int i = N - 1; i >= 0; i--) {
			ord.push(arr[i]);
		}

		Stack<Integer> tmp = new Stack<>();

		int index = 1;

		while (!ord.isEmpty() || !tmp.isEmpty()) {

			// 임시 공간에 가장 앞의 번호표가 현재 통과할 수 있는 번호표인 경우
			if (!tmp.isEmpty()) {
				if (ord.isEmpty() && tmp.peek() != index) break;

				if (tmp.peek() == index) {
					tmp.pop();
					index++;
					continue;
				}
			}

			while (!ord.isEmpty() && ord.peek() != index) {
				// 만약 기존 줄에서 해당하는 번호표가 없는 경우 찾을 때까지 임시 자리로 이동시킨다.
				tmp.push(ord.pop());
			}

			if (!ord.isEmpty() && ord.peek() == index) {
				ord.pop();
				index++;
			}
		}

		if (index == N+1) sb.append("Nice");
		else sb.append("Sad");

		System.out.println(sb);

	}
}
