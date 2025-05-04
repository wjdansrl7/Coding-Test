
import java.util.*;
import java.io.*;

/**
 *packageName    : _250504
 * fileName       : BOJ_S2_14465_소가길을건너간이유5
 * author         : moongi
 * date           : 5/4/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());

		boolean[] visited = new boolean[N + 1];

		int off;
		for (int i = 0; i < B; i++) {
			off = Integer.parseInt(br.readLine());

			// 현재 꺼져있는 상태
			visited[off] = true;

		}

		// 1번부터 K개 까지의 상태에 대하여 수리해야하는 신호등의 개수를 저장.
		int cnt = 0;
		for (int i = 1; i <= K; i++) {
			if (visited[i]) cnt++;
		}
		
		int res = 100_001;
		if (res > cnt) res = cnt;

		int idx = 1;
		for (int i = K + 1; i < N + 1; i++) {
			if (visited[i]) cnt++;
			if (visited[idx++]) cnt--;

			if (res > cnt) res = cnt;
		}

		System.out.println(res);


	}
}
