import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());

		ArrayDeque<String>[] birds = new ArrayDeque[N];
		for (int i = 0; i < N; i++) {
			birds[i] = new ArrayDeque<>();
		}

		// O(N * 100)
		for (int i = 0; i < N; i++) {
			String[] str = br.readLine().split(" ");

			for (int j = 0; j < str.length; j++) {
				birds[i].offer(str[j]);
			}

		}

		String[] res = br.readLine().split(" ");
		boolean flag = false;
		for (int i = 0; i < res.length; i++) {
			String target = res[i];
			flag = false;
			
			for (int j = 0; j < N; j++) {
				if (birds[j].isEmpty()) continue;

				if (birds[j].peek().equals(target)) {
					birds[j].poll();
					flag = true;
					break;
				}
			}
			if (!flag) {
				System.out.println("Impossible");
				return;
			}

		}

		for (int i = 0; i < N; i++) {
			if (!birds[i].isEmpty()) {
				System.out.println("Impossible");
				return;
			}
		}

		System.out.println("Possible");
	}
}