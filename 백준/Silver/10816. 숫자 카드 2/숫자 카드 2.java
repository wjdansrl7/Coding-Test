

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		HashMap<Integer, Integer> map = new HashMap<>();

		int N = Integer.parseInt(br.readLine());

		st = new StringTokenizer(br.readLine());
		int target;
		for (int i = 0; i < N; i++) {
			target = Integer.parseInt(st.nextToken());
			map.put(target, map.getOrDefault(target, 0) + 1);
		}

		int M = Integer.parseInt(br.readLine());

		StringBuilder sb = new StringBuilder();

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			sb.append(map.getOrDefault(Integer.parseInt(st.nextToken()), 0)).append(' ');
		}

		System.out.println(sb);
	}
}
