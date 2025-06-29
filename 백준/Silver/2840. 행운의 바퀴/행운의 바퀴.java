
import java.util.*;
import java.io.*;

/**
 *packageName    : _250629
 * fileName       : BOJ_S4_2840_행운의바퀴
 * author         : moongi
 * date           : 6/29/25
 * description    :
 * 화살표가 가리키는 글자가 변하는 횟수, 어떤 글자에서 회전을 멈추었는지 종이에 적는다.
 * ?A??B
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		char[] arr = new char[N];
		boolean[] visited = new boolean[N];

		int S;
		char c;

		int idx = 0;
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());

			S = Integer.parseInt(st.nextToken());
			c = st.nextToken().charAt(0);
			idx = (idx + S) % N;

			if (visited[idx] && arr[idx] != c) {
				System.out.println("!");
				return;
			}

			visited[idx] = true;
			arr[idx] = c;
		}

		String str = "";
		int size = 0;

		while(size < N) {
			if (idx < 0) idx = N-1;
			str = arr[idx] == 0  ? str.concat("?") : str.concat(String.valueOf(arr[idx]));
			size++;
			idx--;
		}

		boolean[] alpha = new boolean[26];
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == '?') continue;
			int target = str.charAt(i) - 'A';

			if (alpha[target]) {
				System.out.println("!");
				return;
			}

			alpha[target] = true;
		}

		System.out.println(str);
	}
}
