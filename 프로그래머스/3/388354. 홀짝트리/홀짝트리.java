import java.util.*;
import java.io.*;

/**
* [홀짝 트리, 역홀짝 트리]
* 홀수 노드 : 노드의 번호도 홀수이고, 자식 노드의 개수도 홀수인 경우
* 짝수 노드 : 노드의 번호가 짝수이고, 자식 노드의 개수도 짝수인 경우
* 역홀수 노드 : 노드의 번호는 홀수인데, 자식 노드의 개수는 짝수인 경우
* 역짝수 노드 : 노드의 번호는 짝수인데, 자식 노드의 개수는 홀수인 경우
* 
* 홀짝 트리의 경우 모든 리프 노드는 짝수 번호의 리프 노드를 가져야 한다.
* 역홀짝 트리의 경우, 모든 리프 노드는 홀수 번호의 노드를 가져야 한다.
* odd 홀수 even 짝수

** 의문점 1: 만약, root만 다르고 트리의 모양이 동일한 경우는 COUNTING을 어떻게 해줄 것인가 -> 근데 우선 노드의 번호가 달라지면 결과값도 달라질 수 있으므로 다른 케이스로 봐야하지 않을까?
*/

class Solution {
    static class Node {
        int weight;
        List<Integer> childs = new ArrayList<>(); // 노드의 번호가 저장된다.
        
        public Node(int weight) {
            this.weight = weight;
        }
    }
    
    static Node[] nodeList;
    static Map<Integer, Integer> map, count;
    public int[] solution(int[] nodes, int[][] edges) {
        int[] result = new int[2];
        
        nodeList = new Node[nodes.length];
        map = new HashMap<>();
        count = new HashMap<>(); // 자식 노드의 개수가 짝수인지 홀수인지를 파악하기 위해
        
        for(int i = 0; i < nodes.length; i++) {
            nodeList[i] = new Node(nodes[i]);
            map.put(nodes[i], i); // {노드 번호, Node[] 배열의 인덱스}
            count.put(nodes[i], 0);
        }
        
        int a, b;
        for(int i = 0; i < edges.length; i++) {
            a = edges[i][0];
            b = edges[i][1];
            
            nodeList[map.get(a)].childs.add(b);
            nodeList[map.get(b)].childs.add(a);
            
            count.put(a, count.getOrDefault(a, 0) + 1);
            count.put(b, count.getOrDefault(b, 0) + 1);
        }
        
        for(int i = 0; i < nodes.length; i++) {
            int root = nodes[i]; // 현재 루트 노드의 번호
            
            
            Set<Integer> visited = new HashSet<>();
            
            
            // 1. 루트 노드가 홀짝 트리인지 검증
            if(isValid(root, root, visited)) {
                // 1-1. 홀짝 트리인지 검증하고, 맞다면 result++;
                if(solve(root, visited)) {
                    result[0]++;
                }
            }
            
            visited = new HashSet<>();
            
            // 1-2. 역홀짝 트리가 맞는지 검증한다.
            if(!isValid(root, root, visited)) {
                if(reverse(root, visited)) {
                    result[1]++;
                }
            }
        }
        
        return result;
        
    }
    
    static boolean solve(int root, Set<Integer> visited) {
        // 홀짝 트리 여부 확인
        // DFS + memoization
        visited.add(root);
        
        ArrayDeque<Integer> stk = new ArrayDeque<>();
        stk.push(root);
        
        while(!stk.isEmpty()) {
            int p = stk.pop();
            
            for(Integer next : nodeList[map.get(p)].childs) {
                
                if(visited.contains(next)) continue;
                
                // 만약 하나라도 홀짝 트리에 위배된다면 불가능
                if(!isValid(root, next, visited)) return false;
                
                stk.push(next);
                visited.add(next);
            }
        }
        
        return true;
            
    }
    
    static boolean reverse(int root, Set<Integer> visited) {
        // 역홀짝 트리가 맞는지 검증
        // DFS + memoization
        
        visited.add(root);
        
        ArrayDeque<Integer> stk = new ArrayDeque<>();
        stk.push(root);
        
        while(!stk.isEmpty()) {
            
            int p = stk.pop();
                        
            for(Integer next : nodeList[map.get(p)].childs) {
                
                if(visited.contains(next)) continue;
                
                if(isValid(root, next, visited)) return false;
                
                stk.push(next);
                visited.add(next);
            }   
        }
        
        return true;
        
    }
    
    // 홀짝 트리에 대한 유효성 검증
    static boolean isValid(int root, int start, Set<Integer> visited) {
        int cnt = count.get(start);
        if(root != start) cnt--;
        
        if((start & 1) == 0) {
            // 짝수
            if((cnt & 1) == 0) return true;
            else return false;
        } else {
            // 홀수
            if((cnt & 1) == 1) return true;
            else return false;
        }
    }
}