
import java.io.*;
import java.util.*;

/**
 *packageName    : _250507
 * fileName       : BOJ_G3_1278_연극
 * author         : moongi
 * date           : 5/7/25
 * description    :
 *
 * N 명을 가지고, 최대 K개의 장면을 만들어야 한다.
 * 한 장면에는 최소 1명에 배우가 있어야 한다.
 * 처음 장면과 마지막 장면에는 한 명만 존재해야 한다.
 * 장면이 바뀔 때마다 새로운 배우를 넣거나, 기존 배우를 하나 빼는 방법이 있다.
 * 각 장면마다 구성하는 배우들은 모두 달라야 한다.
 * 가능한한 많은 배우들이 출연할 수 있도록 도와줘야 한다.
 *
 *
 */
public class Main {
	static int N, K;
	static boolean[] present, visited;
	static StringBuilder sb;
	static boolean flag;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();

		flag = false;
		N = Integer.parseInt(br.readLine());
		present = new boolean[N + 1];
		visited = new boolean[(int)Math.pow(2, N)]; // 00 01 10 11

		K = (int)Math.pow(2, N) - 1; // 최대 장면의 개수
		List<Integer> li = new ArrayList<>();

		visited[1 << 0] = true;
		present[1] = true;
		li.add(1);

		play(1, 1, 1, li);

		System.out.println(sb);
		
	}

	static void play(int cnt, int curr, int size, List<Integer> li) {
		// 1 -> 1,2 -> 2 -> 0
		if (flag) return;
		if (size == 0) return;
		if (cnt == K && size == 1 && !flag) {
			flag = true;
			sb.append(K).append('\n');
			for(Integer i : li) {
				sb.append(i).append('\n');
			}

			for (int i = 1; i < N + 1; i++) {
				if (present[i]) {
					sb.append(i).append('\n');
					break;
				}
			}
			return;
		}

		for (int i = 1; i < N + 1; i++) {
			int bit = 1 << (i - 1);
			if (present[i]) {
				// 현재 장면에 있다면 빼는 경우의 수만 있음.
				int next = curr ^ bit;

				// but, 뺏을 때 이미 다른 장면에서 촬영했던 기록이 있다면 빼면 안됨.
				if (!isValid(next)) continue;
				if (visited[next]) continue;

				visited[next] = true;
				present[i] = false;
				li.add(i);
				play(cnt + 1, next, size-1, li);
				li.remove(li.size() - 1);
				present[i] = true;
				visited[next] = false;

			} else {
				// 현재 장면에 없다면 추가하는 경우의 수만 있음.
				int next = curr | bit;
				//  해당 배우를 추가해서 촬영한 기록이 있다면 추가하면 안됨.
				if (!isValid(next)) continue;
				if (visited[next]) continue;

				present[i] = true;
				visited[next] = true;
				li.add(i);
				play(cnt + 1, next, size+1, li);
				li.remove(li.size() - 1);
				present[i] = false;
				visited[next] = false;

			}
		}
	}

	static boolean isValid(int x) {
		return x != 0;
	}
}
