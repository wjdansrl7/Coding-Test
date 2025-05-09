
import java.util.*;
import java.io.*;

public class Main {
	static int D, P, res;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		D = Integer.parseInt(st.nextToken()); // 자리수
		P = Integer.parseInt(st.nextToken()); // 연산의 수
		
		res = -1;

		calculator(1, 0, 9);

		System.out.println(res);
	}

	static void calculator(int num, int cnt, int start) {

		if ((num + "").length() > D) {
			return;
		}

		if (cnt == P) {
			res = num > res ? num : res;

			return;
		}

		for (int i = start; i > 1; i--) {
			calculator(num * i, cnt+1, i);
		}
	}
}