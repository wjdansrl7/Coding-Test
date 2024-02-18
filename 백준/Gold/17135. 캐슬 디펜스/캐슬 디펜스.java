import java.io.*;
import java.util.*;

/**
 * packageName    : work_algo.a0219
 * fileName       : BOJ_G3_17135_캐슬디펜스_서울_20반_정문기
 * author         : moongi
 * date           : 2/18/24
 * description    :
 */
public class Main {

    static class Monster implements Comparable<Monster> {
        int x, y, d; // 행, 열, 거리

        public Monster(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }

        @Override
        public int compareTo(Monster o) {
            if (this.d == o.d) { // 거리가 같다면
                return this.y - o.y; // 열이 더 작은 값(더 왼쪽)
            } else
                return this.d - o.d; // 거리가 더 작은 값
        }
    }

    static int N, M, D;
    static int[][] map;
    static List<int[]> list;
    static int[] archer;
    static int res; // 공격할 수 있는 최대 적 수

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        archer = new int[3];
        list = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 1) {
                    list.add(new int[]{i, j});
                }
            }
        }

        locateArcher(0, 0);
        System.out.println(res);
    }

    static void locateArcher(int idx, int start) {
        if (idx == 3) {
            List<int[]> data = copy(list);
            attackMonster(data);
            return;
        }
        for (int i = start; i < M; i++) {
            archer[idx] = i;
            locateArcher(idx + 1, i + 1);
        }

    }

    static void attackMonster(List<int[]> list) {
        int count = 0; // 공격한 몬스터 수

        while (true) {
            if (list.isEmpty()) {
                break;
            }
            List<int[]> targets = new ArrayList<>(); // 궁수 3명이 공격하고자 하는 적의 좌표

            for (int k = 0; k < 3; k++) {
                PriorityQueue<Monster> pq = new PriorityQueue<>(); // 현재 궁수의 사정거리에 있는 몬스터들 저장(거리 순, 열 순 정렬)

                for (int i = 0; i < list.size(); i++) { // 현재 남아있는 몬스터들
                    int[] cur = list.get(i);
                    int d = Math.abs(cur[0] - N) + Math.abs(cur[1] - archer[k]);
                    if(d <= D) // 사정거리 안이면
                        pq.add(new Monster(cur[0], cur[1], d));
                }

                if (!pq.isEmpty()) { // 잡을 몬스터가 있다면
                    Monster target = pq.poll(); // 가장 가깝고, 왼쪽에 있는 적
                    boolean flag = false; // 현재 타겟을 다른 궁수가 잡으려 하는지 여부 / true이면 이미 다른 궁수가 잡으려고 함.
                    for (int i = 0; i < targets.size(); i++) {
                        int[] cur2 = targets.get(i);
                        if (target.x == cur2[0] && target.y == cur2[1])
                            flag = true;
                    }
                    if (!flag) {
                        targets.add(new int[]{target.x, target.y});
                    }
                }
            }
//            targets 리스트에 있는 애들 전부 제거
            for (int i = 0; i < targets.size(); i++) {
                for (int j = list.size()-1; j >= 0; j--) {
                    if (targets.get(i)[0] == list.get(j)[0] && targets.get(i)[1] == list.get(j)[1]) {
                        list.remove(j);
                        count++;
                        break;
                    }
                }
            }

            // 남아있는 몬스터들 이동(좌표 벗어나면 삭제)
            for (int i = list.size()-1; i >= 0; i--) {
                list.get(i)[0] += 1;
                if (list.get(i)[0] == N)
                    list.remove(i);
            }
        }
        res = Math.max(res, count);
    }

    static List<int[]> copy(List<int[]> list) {
        List<int[]> tmp = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            int[] cur = list.get(i);
            tmp.add(new int[]{cur[0], cur[1]});
        }
        return tmp;
    }

}