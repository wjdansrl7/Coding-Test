
import java.util.*;
import java.io.*;

public class Main {
	static class Room {
		int idx;
		char info;
		int amount;

		List<Integer> next = new ArrayList<>();

		public Room(int idx, char info, int amount) {
			this.idx = idx;
			this.info = info;
			this.amount = amount;
		}
	}

	static Room[] rooms;
	static boolean[] visited;
	static int N;
	static boolean flag;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int num;
		while (true) {

			N = Integer.parseInt(br.readLine());
			if (N == 0) break;

			rooms = new Room[N+1];
			visited = new boolean[N + 1];
			flag = false;

			for (int i = 1; i < N + 1; i++) {

				st = new StringTokenizer(br.readLine());

				rooms[i] = new Room(i, st.nextToken().charAt(0), Integer.parseInt(st.nextToken()));

				while (true) {
					num = Integer.parseInt(st.nextToken());
					if (num == 0)
						break;

					rooms[i].next.add(num);
				}
			}

			DFS(1, 0);
			if(flag) sb.append("Yes\n");
			else sb.append("No\n");

		}

		System.out.println(sb);

	}

	static void DFS(int curr, int sum) {

		// 현재 방이 트롤이라면 해당 위치에 통행료를 지불한다.
		if (rooms[curr].info == 'T') {
			sum -= rooms[curr].amount;
		} else {
			// 레프리콘의 경우 자신과 같은 금액으로 맞춰주고, 빈 방일 경우는 sum 보다 크지 못할 것이기 떄문에 고려 X
			if (sum < rooms[curr].amount) {
				sum = rooms[curr].amount;
			}
		}

		if (sum < 0) return;

		// 목표 지점에 도착한 경우
		if (curr == N) {
			flag = true;
			return;
		}

		// 이외의 경우는 현재 방에서 이동 가능한 다른 위치의 방으로 이동시킨다.
		visited[curr] = true;

		for (int i = 0; i < rooms[curr].next.size(); i++) {
			if (visited[rooms[curr].next.get(i)]) continue;

			DFS(rooms[curr].next.get(i), sum);
		}

		visited[curr] = false;
	}
}