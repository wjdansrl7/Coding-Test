
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
/**
 *packageName    : _260302
 * fileName       : BOJ_G4_14499_주사위굴리기
 * author         : moongi
 * date           : 3/2/26
 * description    :
 *
 * 초기 주사위
 * 1 - 6
 * 4 - 3
 * 2 - 5
 *
 * 이동한 칸에 숫자가 0이면, 바닥면이 0으로 복사
 * 0이 아니라면, 칸에 쓰여있는 숫자가 바닥면에 복사, 칸에 쓰여있는 수는 0이 됨
 *
 * 지도 바깥으로 이동하는 경우, 해당 명령 무시
 */
public class Main {
	static int N, M, X, Y, K;
	static int[][] map;
	// dices[1]: 윗면, [2]: 북, [3]: 동, [4]: 서, [5]: 남, [6]: 바닥
	static int[] dices = new int[7];

	// 문제의 명령: 1:동, 2:서, 3:북, 4:남
	static int[] dx = {0, 0, 0, -1, 1};
	static int[] dy = {0, 1, -1, 0, 0};

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken()); // 세로 좌표
		Y = Integer.parseInt(st.nextToken()); // 가로 좌표
		K = Integer.parseInt(st.nextToken());

		map = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < K; i++) {
			int cmd = Integer.parseInt(st.nextToken());

			// 1. 이동할 좌표 계산
			int nx = X + dx[cmd];
			int ny = Y + dy[cmd];

			// 2. 경계 체크: 범위 밖이면 무시 (출력도 안 함)
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			// 3. 주사위 굴리기 (위치 스왑)
			rollDice(cmd);

			// 4. 지도와 주사위 상호작용
			// 바닥면은 항상 dices[6]
			if (map[nx][ny] == 0) {
				map[nx][ny] = dices[6];
			} else {
				dices[6] = map[nx][ny];
				map[nx][ny] = 0;
			}

			// 5. 좌표 업데이트 및 윗면(dices[1]) 출력
			X = nx;
			Y = ny;
			sb.append(dices[1]).append('\n');
		}

		System.out.println(sb);
	}

	// 주사위의 인덱스를 고정하고 값만 옮기는 핵심 로직
	static void rollDice(int cmd) {
		int d1 = dices[1], d2 = dices[2], d3 = dices[3], d4 = dices[4], d5 = dices[5], d6 = dices[6];

		if (cmd == 1) { // 동: 4->1, 1->3, 3->6, 6->4 (북, 남 고정)
			dices[1] = d4; dices[3] = d1; dices[6] = d3; dices[4] = d6;
		} else if (cmd == 2) { // 서: 3->1, 1->4, 4->6, 6->3 (북, 남 고정)
			dices[1] = d3; dices[4] = d1; dices[6] = d4; dices[3] = d6;
		} else if (cmd == 3) { // 북: 5->1, 1->2, 2->6, 6->5 (동, 서 고정)
			dices[1] = d5; dices[2] = d1; dices[6] = d2; dices[5] = d6;
		} else if (cmd == 4) { // 남: 2->1, 1->5, 5->6, 6->2 (동, 서 고정)
			dices[1] = d2; dices[5] = d1; dices[6] = d5; dices[2] = d6;
		}
	}
}