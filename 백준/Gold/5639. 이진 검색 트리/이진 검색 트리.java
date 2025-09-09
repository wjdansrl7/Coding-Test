import java.util.*;
import java.io.*;

/**
 *packageName    : _250909
 * fileName       : BOJ_G4_5639_이진검색트리
 * author         : moongi
 * date           : 9/9/25
 * description    :
 */
public class Main {
	static class Node {
		int weight;
		Node left, right;

		public Node(int weight, Node left, Node right) {
			this.weight = weight;
			this.left = left;
			this.right = right;
		}
	}

	static Node[] nodes;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		// 전위 순회한 결과 (Root - L - R)
		String W = br.readLine();

		Node root = new Node(Integer.parseInt(W), null, null);


		while (true) {

			W = br.readLine();
			if (W == null || W.equals("") || W == "") break;

			DFS(root, Integer.parseInt(W));
		}

		// 후위 순회한 결과로 반환 (L - R - Root)
		PostOrder(root);
		System.out.println(sb);
	}

	static void PostOrder(Node root) {

		if(root.left != null) PostOrder(root.left);
		if(root.right != null) PostOrder(root.right);
		sb.append(root.weight).append('\n');

	}

	static void DFS(Node cur, int weight) {

		if (cur.weight <= weight) {
			// right
			if(cur.right != null) DFS(cur.right, weight);
			else cur.right = new Node(weight, null, null);
		} else {
			// left
			if(cur.left != null) DFS(cur.left, weight);
			else cur.left = new Node(weight, null, null);
		}
	}
}