import java.util.*;
import java.io.*;

/*
LIS에 대한 구현 방식 -> 이진 탐색을 활용하여 O(nlogN)을 이용하여 해결한다.
 */
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        List<Integer> LIS = new ArrayList<>();
        LIS.add(0);

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int value = arr[i] = Integer.parseInt(st.nextToken());

            if (LIS.get(LIS.size() - 1) < value) LIS.add(value);
            else {
                int start = 0, end = LIS.size()-1;

                while (start < end) {
                    int mid = (start + end) >> 1;

                    if (LIS.get(mid) >= value) end = mid;
                    else start = mid + 1;
                }
                LIS.set(end, value);
            }
        }
        System.out.println(LIS.size()-1);
    }
}