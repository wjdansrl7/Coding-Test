import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb;
		boolean[][] arr = new boolean[101][101];
		int n = Integer.parseInt(br.readLine());
		
		int a, b;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			
			for (int j = b; j < b+10; j++)
				for (int k = a; k < a + 10; k++)
					arr[j][k] = true;
		}
		int sum = 0;
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++)
				if(arr[i][j]) sum++;
		System.out.println(sum);
	}
}