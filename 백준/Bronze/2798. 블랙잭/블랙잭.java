import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, m;
	static int[] arr, b;
	static int res = -1;
	
	static void Combi(int cnt, int start) {
		if(cnt == 3) {
			int sum = 0;
			for (int i = 0; i < 3; i++) {
				sum += b[i];
			}
			if(sum <= m && sum > res) {
				res = sum;
			}
			return;
		}
		
		for (int i = start; i < n; i++) {
			b[cnt] = arr[i];
			Combi(cnt+1, i+1);
		}
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine(), " ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		arr = new int[n];
		b = new int[n];

		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		

		Combi(0,0);
		System.out.println(res);
		
		
		
	}
}