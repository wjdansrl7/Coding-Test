import java.io.*;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[][] arr;
	static int b = 0, w = 0;
	static void makePaper(int N, int x, int y) {
		boolean flag = true;
		label: for (int i = x; i < x+N; i++) {
			for (int j = y; j < y+N; j++) {
				if(arr[x][y] != arr[i][j]) {
					flag = false;
					break label;
				}
			}
		}
		if(flag) {
			if(arr[x][y] == 0) w++;
			else b++;
		} else {
			makePaper(N >> 1, x, y);
			makePaper(N >> 1, x, y + (N >> 1));
			makePaper(N >> 1, x + (N >> 1), y);
			makePaper(N >> 1, x + (N >> 1), y + (N >> 1));
		}
		
		
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		
		arr = new int[N][N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		makePaper(N, 0, 0);
		
		System.out.println(w);
		System.out.println(b);
	}
}