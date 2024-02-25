import java.io.*;
import java.util.*;

public class Main {
	
	static int[] a;
	static int n, m;
	
	static void Combi(int cnt, int start) {
		if(cnt == m) {
			for (int i = 0; i < m; i++) {
				System.out.print(a[i] + " ");
			}
			System.out.println();
			return;
		}
		
		for (int i = start; i <= n; i++) {
			a[cnt] = i;
			Combi(cnt+1, i);
		}
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine(), " ");
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		a = new int[m];
		
		Combi(0, 1);
		
		br.close();
	}
}