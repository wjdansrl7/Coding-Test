
import java.io.*;
import java.util.*;

public class Main {
	static class TreeNode {
		List<TreeNode> children;
		public TreeNode() {
			children = new ArrayList<>();
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for (int tc = 0; tc < T; tc++) {
			StringTokenizer st1 = new StringTokenizer(br.readLine());
			StringTokenizer st2 = new StringTokenizer(br.readLine());

			List<String> list1 = new ArrayList<>();
			List<String> list2 = new ArrayList<>();
			while (st1.hasMoreTokens()) {
				list1.add(st1.nextToken());
			}
			while (st2.hasMoreTokens()) {
				list2.add(st2.nextToken());
			}

			int[] index1 = {0};
			int[] index2 = {0};
			TreeNode root1 = buildTree(list1, index1);
			TreeNode root2 = buildTree(list2, index2);

			String can1 = canonical(root1);
			String can2 = canonical(root2);

			if (can1.equals(can2)) {
				System.out.println("The two trees are isomorphic.");
			} else {
				System.out.println("The two trees are not isomorphic.");
			}
		}
	}

	private static TreeNode buildTree(List<String> list, int[] index) {
		if (index[0] >= list.size()) return null;

		list.get(index[0]++);
		TreeNode node = new TreeNode();

		while (index[0] < list.size() && !list.get(index[0]).equals("#")) {
			TreeNode child = buildTree(list, index);
			node.children.add(child);
		}

		if (index[0] < list.size() && list.get(index[0]).equals("#")) {
			index[0]++;
		}

		return node;
	}

	private static String canonical(TreeNode node) {
		if (node == null) return "";
		List<String> childReps = new ArrayList<>();
		for (TreeNode child : node.children) {
			childReps.add(canonical(child));
		}
		Collections.sort(childReps);
		StringBuilder sb = new StringBuilder();
		sb.append("(");
		for (String rep : childReps) {
			sb.append(rep);
		}
		sb.append(")");
		return sb.toString();
	}
}
