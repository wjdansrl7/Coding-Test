import java.io.*;
import java.util.*;

/**
 * packageName    : _241021
 * fileName       : BOJ_G2_1202_보석도둑
 * author         : moongi
 * date           : 10/21/24
 * description    :
 * Comparable -> compareTo(Object o)를 사용하고, Collections.sort()에서 사용할 수 있다.
 * Comparator -> compare(Object o1, Object o2)를 사용하고 Collections.sort(DataStructure, new customComparator());
 *
 */
public class Main {
    static class Jewelry implements Comparable<Jewelry>{
        int m, v;

        public Jewelry(int m, int v) {
            this.m = m;
            this.v = v;
        }
        @Override
        public int compareTo(Jewelry o) {
            if (this.m == o.m) return this.v - o.v;
            return this.m - o.m;
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        List<Jewelry> jewelries = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            jewelries.add(new Jewelry(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        Collections.sort(jewelries);

        int[] bags = new int[K];

        for (int i = 0; i < K; i++) {
            bags[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(bags);
        long res = 0;
        // 보석 가격을 저장하는 pq -> 가장 작은 무게의 가방부터 순서대로 보석들의 무게와 비교하여 넣을 수 있다면, 보석을 pq에 집어넣는다.
        // 이때, 보석의 가격의 합이 내림차순으로 저장되기 때문에, 마지막에 해당 가방에 넣을 수 있는 보석 중에 가장 비싼 보석이 첫 번째 보석이 된다.
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int i = 0, j = 0; i < K; i++) {
            while (j < N && jewelries.get(j).m <= bags[i]) {
                pq.offer(jewelries.get(j++).v);
            }
            if (!pq.isEmpty()) res += pq.poll();
        }
        System.out.println(res);
    }
}