import java.io.*;
import java.util.*;

public class Main {
	
	static int w, h;
	static int[][] arr;
	static boolean[][] v;
	static int[] dx= {-1,0,1,0,-1,-1,1,1},dy= {0,1,0,-1,-1,1,-1,1};
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		while(true) {			
			st = new StringTokenizer(br.readLine());
			w = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			
			if(w == 0 && h == 0)
				return;
			
			arr = new int[h][w];
			v = new boolean[h][w];
			
			for (int i = 0; i < h; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < w; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			int cnt = 0;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if(!v[i][j] && arr[i][j]==1) {
						bfs(i, j);
						cnt++;
					}
				}
			}
			System.out.println(cnt);
		}
	}
	static void bfs(int x, int y) {
		ArrayDeque<int[]> q = new ArrayDeque<>();
		v[x][y]=true;
		q.offer(new int[] {x, y});
		
		while(!q.isEmpty()) {
			int[] p = q.poll();
			
			for (int d = 0; d < 8; d++) {
				int nx = p[0]+dx[d];
				int ny = p[1]+dy[d];
				
				if(nx>=0&&nx<h&&ny>=0&&ny<w&&arr[nx][ny]==1&&!v[nx][ny]) {
					q.offer(new int[] {nx, ny});
					v[nx][ny]=true;
				}
			}
		}
	}
}