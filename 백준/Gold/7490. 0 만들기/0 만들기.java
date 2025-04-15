
import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {
	static int N;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());

		for (int tc = 0; tc < T; tc++) {
			N = Integer.parseInt(br.readLine());

			operator(1, 1, "1");
			sb.append('\n');
		}

		System.out.println(sb);

	}

	static void operator(int num, int cnt, String str) {

		if (cnt == N) {
			if (calculate(str) == 0) {
				sb.append(str).append('\n');
			}
			return;
		}

		operator(num + 1, cnt + 1, str + ' ' + (num + 1));
		operator(num + 1, cnt + 1, str + '+' + (num + 1));
		operator(num + 1, cnt + 1, str + '-' + (num + 1));

	}

	static int calculate(String str) {
		str = str.replaceAll(" ", "");
		Iterator<Integer> it = Arrays.stream(str.split("[+-]"))
			.map(Integer::parseInt)
			.collect(Collectors.toList()).iterator();

		int res = it.next();

		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == '+') {
				res += it.next();
			} else if (str.charAt(i) == '-') {
				res -= it.next();
			}
		}

		return res;
	}
}
