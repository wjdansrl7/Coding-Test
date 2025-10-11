import java.io.*;
import java.util.*;

/**
 *packageName    : _251011
 * fileName       : BOJ_G4_2251_물통
 * author         : moongi
 * date           : 10/11/25
 * description    : 각각의 A, B는 비어있는 상태에서 C가 가질 수 있는 물통의 양
 *
 * 현재 들어있는 물의 양
 *
 * if A에 들어있는 물의 양이 0이라면 현재 들어있는 C의 물의 양 저장
 * 8 9 10
 *
 * 8 0 2
 * 0 8 2
 * 0 9 1
 *
 */
public class Main {
	static int A, B, C; // 각각의 물통의 용량
	static Set<Integer> set;
	static boolean[][] visited;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		A = Integer.parseInt(st.nextToken());
		B = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		set = new TreeSet<>();
		visited = new boolean[201][201];

		moveWater(0, 0, C);

		for (Integer v : set)
			sb.append(v).append(" ");

		System.out.println(sb);

	}

	static void moveWater(int curA, int curB, int curC) {
		if (visited[curA][curB])
			return;

		if (curA == 0) {
			set.add(curC);
		}

		visited[curA][curB] = true;

		// A <- C
		if (curA + curC > A) {
			moveWater(A, curB, curC - (A - curA));
		} else {
			moveWater(curA + curC, curB, 0);
		}

		// B <- C
		if (curB + curC > B) {
			moveWater(curA, B, curC - (B - curB));
		} else {
			moveWater(curA, curB + curC, 0);
		}

		// A <- B
		if (curA + curB > A) {
			moveWater(A, curB - (A - curA), curC);
		} else {
			moveWater(curA + curB, 0, curC);
		}

		// C <- B
		moveWater(curA, 0, curB + curC);

		// B <- A
		if (curA + curB > B) {
			moveWater(curA - (B - curB), B, curC);
		} else {
			moveWater(0, curA + curB, curC);
		}

		// C <- A
		moveWater(0, curB, curA + curC);

	}
}