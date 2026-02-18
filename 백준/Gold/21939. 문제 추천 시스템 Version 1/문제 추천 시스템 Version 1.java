import java.util.*;
import java.io.*;
/**
 *packageName    : _260218
 * fileName       : BOJ_G4_21939_문제추천시스템Version1
 * author         : moongi
 * date           : 2/18/26
 * description    :
 *
 * recommend x
 * 1: print ver hard problem and
 * if problems are several, biggest Number
 * -1: print ver easy problem and
 * if problem are several, smallest Number
 * app P L: add level L, No.P
 * solved P : remove No.P
 */
public class Main {
	static StringBuilder sb = new StringBuilder();

	static class Problem implements Comparable<Problem> {
		int id, level;

		public Problem(int id, int level) {
			this.id = id;
			this.level = level;
		}

		@Override
		public int compareTo(Problem o) {

			if (this.level == o.level) {
				return this.id - o.id; // 난이도 같으면 번호순
			}

			return this.level - o.level; // 난이도순
		}
	}

	static TreeSet<Problem> ts = new TreeSet<>();
	static Map<Integer, Integer> map = new HashMap<>();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			// P L
			st = new StringTokenizer(br.readLine());
			int P = Integer.parseInt(st.nextToken());
			int L = Integer.parseInt(st.nextToken());

			ts.add(new Problem(P, L));
			map.put(P, L);
		}

		int M = Integer.parseInt(br.readLine());
		for (int i = 0; i < M; i++) {
			String[] cmd = br.readLine().split(" ");

			processCmd(cmd);
		}
		System.out.println(sb);
	}

	static void processCmd(String[] cmd) {
		int P = cmd[1] != null || !cmd[1].isEmpty() ? Integer.valueOf(cmd[1]) : -1;

 		if (cmd[0].equals("add")) {
			int L = Integer.valueOf(cmd[2]);
			ts.add(new Problem(P, L));
			map.put(P, L);
		} else if (cmd[0].equals("recommend")) {

			if (cmd[1].equals("1")) {
				// print hard problem.
				sb.append(ts.last().id).append('\n');
			} else {
				// print easy problem.
				sb.append(ts.first().id).append('\n');
			}

		} else {
			int level = map.get(Integer.valueOf(cmd[1]));
			ts.remove(new Problem(P, level)); // 정확한 객체를 생성해 TreeSet에서 O(log N)으로 삭제
			map.remove(P);
		}
	}
}