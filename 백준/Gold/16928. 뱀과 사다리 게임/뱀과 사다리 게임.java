import java.util.*;
import java.io.*;
/**
 * packageName    : _241227
 * fileName       : BOJ_G5_16928_뱀과사다리게임_최적화
 * author         : moongi
 * date           : 12/27/24
 * description    :
 */
public class Main {
    static int N, M;
    static Map<Integer, Integer> map;
    static boolean[] visited;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new HashMap<>();
        visited = new boolean[101];

        for (int i = 0; i < N + M; i++) {
            st = new StringTokenizer(br.readLine());
            map.put(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        System.out.println(bfs());

    }

    static int bfs() {
        int res = 0;
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.offer(1);
        visited[1] = true;

        while (!q.isEmpty()) {
            res++;
            // queue 크기가 변동이 있기 떄문에 고정을 시켜줘야 한다.
            for (int i = 0, qSize = q.size(); i < qSize; i++) {
                int curr = q.poll();

                for (int j = 1; j < 7; j++) {
                    int move = curr + j;

                    if (move == 100) return res;
                    if (move > 100) continue;
                    if (visited[move]) continue;

                    visited[move] = true;
                    if (map.containsKey(move)) {
                        move = map.get(move);
                    }
                    q.offer(move);
                }
            }
        }
        return res;
    }
}