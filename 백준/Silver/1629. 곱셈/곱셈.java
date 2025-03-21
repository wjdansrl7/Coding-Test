
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int A, B, C;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		A = Integer.parseInt(st.nextToken());
		B = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		System.out.println(multiply(A, B, C));
		
	}

	static long multiply(int n, int exp, int mod) {

		if (exp == 1) return n % mod;

		long res = multiply(n, exp / 2, mod);

		res = res * res % mod;

		if (exp % 2 == 1) res = res * n % mod;

		return res;
	}
}