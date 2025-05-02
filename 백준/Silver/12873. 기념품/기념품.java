import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());

		// 단계별로 t^3에 해당하는 위치에 사람을 제거한다.
		List<Integer> players = new ArrayList<>();

		for (int i = 1; i < N + 1; i++) {
			players.add(i);
		}

		long t = 1;
		int curr = 0;
		while (players.size() != 1) {

			int removeIdx = (int)((curr + (long) t * t * t - 1) % players.size());
			players.remove(removeIdx);
			curr = removeIdx;
			t++;
		}

		sb.append(players.get(0));
		System.out.println(sb);
	}
}
