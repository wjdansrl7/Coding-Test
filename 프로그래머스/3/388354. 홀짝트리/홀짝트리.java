import java.util.*;
import java.io.*;

class Solution {
    static class Node {
        int weight;
        List<Integer> childs = new ArrayList<>();
        
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
        count = new HashMap<>();
        
        for(int i = 0; i < nodes.length; i++) {
            nodeList[i] = new Node(nodes[i]);
            map.put(nodes[i], i);
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
            int root = nodes[i];
            
            
            Set<Integer> visited = new HashSet<>();
                        
            if(isValid(root, root, visited)) {
                if(solve(root, visited)) {
                    result[0]++;
                }
            }
            
            visited = new HashSet<>();
            
            if(!isValid(root, root, visited)) {
                if(reverse(root, visited)) {
                    result[1]++;
                }
            }
        }
        
        return result;
        
    }
    
    static boolean solve(int root, Set<Integer> visited) {
        visited.add(root);
        
        ArrayDeque<Integer> stk = new ArrayDeque<>();
        stk.push(root);
        
        while(!stk.isEmpty()) {
            int p = stk.pop();
            
            for(Integer next : nodeList[map.get(p)].childs) {
                
                if(visited.contains(next)) continue;
                
                if(!isValid(root, next, visited)) return false;
                
                stk.push(next);
                visited.add(next);
            }
        }
        
        return true;
            
    }
    
    static boolean reverse(int root, Set<Integer> visited) {
        
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
    
    static boolean isValid(int root, int start, Set<Integer> visited) {
        int cnt = count.get(start);
        if(root != start) cnt--;
        
        if((start & 1) == 0) {
            if((cnt & 1) == 0) return true;
            else return false;
        } else {
            if((cnt & 1) == 1) return true;
            else return false;
        }
    }
}