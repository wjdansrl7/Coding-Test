
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		boolean[] alphabet = new boolean[26];

		int[] keyword = new int[N];
		Arrays.fill(keyword, -1);

		String[] options = new String[N];
		String str;

		int idx = 0;
		boolean flag;

		for (int i = 0; i < N; i++) {
			str = br.readLine();
			options[i] = str;
			flag = false;

			String[] tmp = str.split(" ");

			for (int j = 0; j < tmp.length; j++) {
				idx = Character.toLowerCase(tmp[j].charAt(0)) - 'a';
				if (idx >= 0 && !alphabet[idx]) {
					alphabet[idx] = true;
					keyword[i] = 0;
					for (int k = 0; k < j; k++) {
						keyword[i] += tmp[k].length() + 1;
					}
					flag = true;
					break;
				}
			}

			if (!flag) {
				for (int j = 0; j < str.length(); j++) {
					idx = Character.toLowerCase(str.charAt(j)) - 'a';

					if (idx >= 0 && !alphabet[idx]) {
						alphabet[idx] = true;
						keyword[i] = idx;
						keyword[i] = j;
						break;
					}
				}
			}
		}
		String[] res = new String[N];
		Arrays.fill(res, "");

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < options[i].length(); j++) {
				if (keyword[i] == j) {
					res[i] = res[i].concat("[" + options[i].charAt(j) + "]");
					continue;
				}
				res[i] += options[i].charAt(j);
			}
		}
		for (int i = 0; i < N; i++) {
			sb.append(res[i]).append('\n');
		}
		System.out.println(sb);

	}
}
