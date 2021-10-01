public class TreeTraversals {
 public void inorderRecursive(Node root) {
 if (root != null) {
 inorderRecursive(root.left);
 System.out.print(root.data + " ");
 inorderRecursive(root.right);
 }
 }

 public void postOrderRecursive(Node root) {
 if (root != null) {
 postOrderRecursive(root.right);
 postOrderRecursive(root.left);
 System.out.print(root.data + " ");
 }
 }

 public void preOrderRecursive(Node root) {
 if (root != null) {
 System.out.print(root.data + " ");
 preOrderRecursive(root.left);
 preOrderRecursive(root.right);
 }
 }

 public static void main(String[] args) {
 Node root = new Node(1);
 root.left = new Node(2);
 root.right = new Node(3);
 root.left.left = new Node(4);
 root.left.right = new Node(5);
 root.right.left = new Node(6);
 root.right.right = new Node(7);

 TreeTraversals i = new TreeTraversals();
 System.out.println("Inorder Traversal:");
 i.inorderRecursive(root);
 System.out.println("\nPreorder Traversal:");
 i.preOrderRecursive(root);
 System.out.println("\nPostorder Traversal:");
 i.postOrderRecursive(root);
 }
}

class Node {
 int data;
 Node left;
 Node right;

 public Node(int data) {
 this.data = data;
 }
}
