
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		String[] str = new String[N];

		for (int i = 0; i < N; i++) {
			str[i] = br.readLine();
		}

		String tmp = "";
		for (int i = 0; i < N; i++) {
			if (str[i].equals("KBS1")) {
				tmp = "";
				for (int j = i; j > 0; j--) {
					sb.append(4);
					tmp = str[j - 1];
					str[j - 1] = str[j];
					str[j] = tmp;
				}
				break;
			} else {
				sb.append(1);
			}
		}

		if (str[1].equals("KBS2")) {
			System.out.println(sb);
			return;
		}

		for (int i = 0; i < N; i++) {
			if (str[i].equals("KBS2")) {
				tmp = "";
				for (int j = i; j > 1; j--) {
					sb.append(4);
					tmp = str[j - 1];
					str[j - 1] = str[j];
					str[j] = tmp;
				}
				break;
			} else {
				sb.append(1);
			}
		}

		System.out.println(sb);
		

	}
}
