
import java.io.*;
import java.util.*;
/**
 *packageName    : _250718
 * fileName       : BOJ_G5_2302_극장좌석
 * author         : moongi
 * date           : 7/18/25
 * description    :
 */
public class Main {
	static int N, ans;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		ans = 0;

		int M = Integer.parseInt(br.readLine());
		boolean[] visited = new boolean[N + 1];

		int num;
		for (int i = 0; i < M; i++) {
			num = Integer.parseInt(br.readLine());
			visited[num] = true;
		}

		comb(visited, 1);

		sb.append(ans);
		System.out.println(sb);
		
	}

	static void comb(boolean[] visited, int cnt) {
		// visited: 좌석번호, cnt: 입장권 번호
		if (cnt == N + 1) {
			ans++;

			return;
		}

		if (visited[cnt]) {
			comb(visited, cnt+1);
			return;
		}


		if (cnt-1 > 0 && !visited[cnt-1]) {
			// 만약 입장권 번호보다 작은 좌석 번호가 아무도 앉지 않은 경우
			visited[cnt - 1] = true;
			comb(visited, cnt + 1);
			visited[cnt - 1] = false;
		}

		if (cnt > 0 && !visited[cnt]) {
			visited[cnt] = true;
			comb(visited, cnt + 1);
			visited[cnt] = false;
		}

		if (cnt + 1 <= N && !visited[cnt + 1]) {
			visited[cnt+1] = true;
			comb(visited, cnt + 1);
			visited[cnt+1] = false;
		}
	}
}
