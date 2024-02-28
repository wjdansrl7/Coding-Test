import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int[][] arr = new int[N][M];
		int[][] dp = new int[N][M];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if(i-1>=0 && i-1<N && j>=0 && j < M) dp[i][j] = Math.max(dp[i][j], dp[i-1][j]);
				if(i>=0 && i < N && j-1>=0 &&j-1 < M) dp[i][j] = Math.max(dp[i][j], dp[i][j-1]);
				if(i-1>=0 && i-1 < N && j-1 >= 0 && j-1 < M) dp[i][j] = Math.max(dp[i][j], dp[i-1][j-1]);
				
				dp[i][j] += arr[i][j];
			}
		}
		System.out.println(dp[N-1][M-1]);
		
		br.close();
	}
}