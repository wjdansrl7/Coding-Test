
import java.util.*;
import java.io.*;

public class Main {
	static boolean[] visited;
	static int N, res;
	
	static void dfs(int idx, int channel) {
		for (int i = 0; i < 10; i++) {
			if (!visited[i]) {
				int newChannel = channel * 10 + i;
				int cnt = Math.abs(N - newChannel) + String.valueOf(newChannel).length();
				
				res = res > cnt ? cnt : res;
				
				if (idx < 6)
					dfs(idx + 1, newChannel);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		
		res = Math.abs(100 - N);

		visited = new boolean[10];
		
		if (M > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			for (int i = 0; i < M; i++) {
				visited[Integer.parseInt(st.nextToken())] = true;
			}
		}

		dfs(0, 0);

		System.out.println(res);
	}
}
