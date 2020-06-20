package com.java.code.roop.four;

class Node {

	int data;
	Node left, right, parent;

	Node(int d) {
		data = d;
		left = right = parent = null;
	}
}

public class ArrayToBST {

	static Node root;

	Node sortedArrayToBST(int arr[], int start, int end) {

		if (start > end) {
			return null;
		}

		int mid = (start + end) / 2;
		Node node = new Node(arr[mid]);
		node.left = sortedArrayToBST(arr, start, mid - 1);
		node.right = sortedArrayToBST(arr, mid + 1, end);
		return node;
	}

	void preOrder(Node node) {
		if (node == null) {
			return;
		}
		System.out.print(node.data + " ");
		preOrder(node.left);
		preOrder(node.right);
	}

	public static void main(String[] args) {
		ArrayToBST tree = new ArrayToBST();
		int arr[] = new int[] { 1, 2, 3, 4, 5, 6, 7 };
		int n = arr.length;
		root = tree.sortedArrayToBST(arr, 0, n - 1);
		System.out.println("Preorder traversal of constructed BST");
		tree.preOrder(root);
	}

}
