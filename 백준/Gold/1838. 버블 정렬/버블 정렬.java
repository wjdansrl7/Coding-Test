import java.util.*;
import java.io.*;

// 버블 정렬: 이동이 더이상 일어나지 않는다면 정렬이 완료된 상태
// 한 번의 sort 이후, 가장 큰 수는 가장 오른쪽으로 이동
// 작은 값들은 한 칸씩 앞으로 이동한다.
// 따라서 인덱스를 기준으로 처음 인덱스에서 얼마나 바뀌었는지에 대한 차이의 max값을 구하면 정렬 횟수를 구할 수 있다.
// 반례: 배열에서 가장 큰 값을 기준으로 인덱스의 변화를 살펴본다면? 5 3 2 1 4 일 경우, 5는 이동횟수는 가장 컸지만, 실제로는 한 바퀴만 이동한 것이므로 반례가 된다.
// 반례: 배열에서 가장 작은 값을 기준으로 잡는다면? 3 1 4 2 5 를 기준으로 본다면, 1은 한 번의 이동 이후 더이상 이동하지 않지만, 2는 2번의 이동해야하므로 max값을 구해야하는 것
// 결론: 정렬하기 전 인덱스 - 정렬 후 인덱스 > 0 후보중에서 max값을 구한다.

public class Main {
    static int n;

    static class Node implements Comparable<Node>{
        int idx, value;

        public Node(int idx, int value) {
            this.idx = idx;
            this.value = value;
        }
        @Override
        public int compareTo(Node o) {
            return this.value - o.value;
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        PriorityQueue<Node> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) pq.offer(new Node(i, Integer.parseInt(st.nextToken())));
        int max = 0, index = 0;

        while (!pq.isEmpty()) {
            Node p = pq.poll();
            if (p.idx > index) max = max < p.idx - index ? p.idx - index : max;
            index++;
        }
        System.out.println(max);
    }
}