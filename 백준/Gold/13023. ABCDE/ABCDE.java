import java.io.*;
import java.util.*;

public class Main {
	static int n, m, res = 0;
	static List<Integer>[] connect;
	static boolean[] v;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		connect = new List[n];
		
		for (int i = 0; i < n; i++)
			connect[i] = new ArrayList<>();

		int a = 0, b = 0;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			connect[a].add(b);
			connect[b].add(a);
		}

		v = new boolean[n];
		for (int i = 0; i < n; i++) {
			v[i]=true;
			DFS(i, 1);
			v[i]=false;
			if (res == 1)
				break;
		}
		System.out.println(res);
	}

	static void DFS(int x, int cnt) {
		if (cnt == 5) {
			res = 1;
			return;
		}
		
		for(int i : connect[x]) {
			if(v[i]) continue;
			v[i] = true;
			DFS(i, cnt+1);
			v[i] = false;
		}
	}
}