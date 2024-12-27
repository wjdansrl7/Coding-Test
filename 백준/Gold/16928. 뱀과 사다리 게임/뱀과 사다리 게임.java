import java.io.*;
import java.util.*;

/**
 * packageName    : _241227
 * fileName       : BOJ_G5_16928_뱀과사다리게임
 * author         : moongi
 * date           : 12/27/24
 * description    :
 */
public class Main {
    static int N, M, res = 18;
    static int[] visited;
    static class Dice {
        int target;
        int cnt;

        public Dice(int target, int cnt) {
            this.target = target;
            this.cnt = cnt;
        }
    }
    // 잊지말자.
    static class DiceComparator implements Comparator<Dice> {
        @Override
        public int compare(Dice o1, Dice o2) {
            return Integer.compare(o2.target, o1.target);
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        visited = new int[101];
        Arrays.fill(visited, 18);

        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 1; i < 101; i++) map.put(i, map.getOrDefault(i, i));

        for (int i = 0; i < N + M; i++) {
            st = new StringTokenizer(br.readLine());
            map.put(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        PriorityQueue<Dice> maxHeap = new PriorityQueue<>(new DiceComparator());

//        PriorityQueue<Dice> m = new PriorityQueue<>(new Comparator<Dice>() {
//            @Override
//            public int compare(Dice o1, Dice o2) {
//                return Integer.compare(o2.target, o1.target);
//            }
//        });

        maxHeap.offer(new Dice(1, 0));

        while (!maxHeap.isEmpty()) {
            Dice curr = maxHeap.poll();
            if (curr.cnt >= res) continue;

            if (curr.target == 100) {
                res = curr.cnt;
                continue;
            }
            for (int i = 1; i <= 6; i++) {
                if (curr.target+i <= 100 && visited[map.get(curr.target + i)] >= curr.cnt + 1) {
                    visited[map.get(curr.target + i)] = curr.cnt + 1;
                    maxHeap.offer(new Dice(map.get(curr.target+i), visited[map.get(curr.target + i)]));
                }
            }
        }
        System.out.println(res);
    }
}