import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static Node root;
    static class Node {
        char data;
        Node left, right;

        public Node(char data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        String a, b, c;
        st = new StringTokenizer(br.readLine());

        a = st.nextToken();
        b = st.nextToken();
        c = st.nextToken();

        root = new Node(a.charAt(0), null, null);
        Node n1, n2;
        if (!b.equals(".")){
            n1 = new Node(b.charAt(0), null, null);
            root.left = n1;
        }
        if (!c.equals(".")){
            n2 = new Node(c.charAt(0), null, null);
            root.right = n2;
        }
        for (int i = 0; i < n-1; i++) {
            st = new StringTokenizer(br.readLine());
            a = st.nextToken();
            b = st.nextToken();
            c = st.nextToken();

            dfs(a,b,c, root);
        }
        preorder(root);
        sb.append('\n');
        inorder(root);
        sb.append('\n');
        postorder(root);
        System.out.println(sb);
    }

    private static void postorder(Node node) {
        if (node.left!=null) postorder(node.left);
        if (node.right!=null) postorder(node.right);
        sb.append(node.data);
    }

    private static void inorder(Node node) {
        if (node.left!=null) inorder(node.left);
        sb.append(node.data);
        if (node.right!=null) inorder(node.right);
    }

    private static void preorder(Node node) {
        sb.append(node.data);
        if (node.left!=null) preorder(node.left);
        if (node.right!=null) preorder(node.right);
    }

    static void dfs(String a, String b, String c, Node node) {
        if (node.data != a.charAt(0)) {
            if (node.left != null) {
                dfs(a, b, c, node.left);
            }
            if (node.right != null) {
                dfs(a, b, c, node.right);
            }
        } else {
            Node n1, n2;
            if (!b.equals(".")) {
                n1 = new Node(b.charAt(0), null, null);
                node.left = n1;
            }
            if (!c.equals(".")) {
                n2 = new Node(c.charAt(0), null, null);
                node.right = n2;
            }
        }
    }
}