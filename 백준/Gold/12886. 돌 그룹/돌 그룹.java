
import java.util.*;
import java.io.*;

public class Main {
	static class Stone {
		int a, b, c;

		public Stone(int a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		ArrayDeque<Stone> q = new ArrayDeque<>();
		boolean[][] visited = new boolean[1501][1501];

		q.offer(new Stone(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
			Integer.parseInt(st.nextToken())));

		while (!q.isEmpty()) {
			Stone p = q.poll();

			if (p.a == p.b && p.b == p.c) {
				System.out.println(1);
				return;
			}

			if (p.a != p.b) {
				int na = p.a > p.b ? p.a-p.b :p.a + p.a;
				int nb = p.a > p.b ? p.b + p.b : p.b - p.a;

				if (!visited[na][nb]) {
					visited[na][nb] = true;
					q.offer(new Stone(na, nb, p.c));
				}
			} 
			
			if (p.a != p.c) {
				int na = p.a > p.c ? p.a - p.c : p.a + p.a;
				int nc = p.a > p.c ? p.c + p.c : p.c - p.a;
				
				if(!visited[na][nc]) {
					visited[na][nc] = true;
					q.offer(new Stone(na, p.b, nc));
				}
			}
			
			if (p.b != p.c) {
				int nb = p.b > p.c ? p.b - p.c : p.b + p.b;
				int nc = p.b > p.c ? p.c + p.c : p.c - p.b;

				if (!visited[nb][nc]) {
					visited[nb][nc] = true;
					q.offer(new Stone(p.a, nb, nc));
				}
			}
		}
		System.out.println(0);
	}
}
