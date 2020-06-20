package com.java.code.roop.four;

public class Successor {

	Node insert(Node node, int data) {

		if (node == null) {
			return (new Node(data));
		} else {
			Node temp = null;
			if (data <= node.data) {
				temp = insert(node.left, data);
				node.left = temp;
				temp.parent = node;
			} else {
				temp = insert(node.right, data);
				node.right = temp;
				temp.parent = node;
			}
			return node;
		}
	}

	Node inOrderSuccessor(Node root, Node temp) {

		if (temp.right != null) {
			Node current = temp.right;
			while (current.left != null) {
				current = current.left;
			}
			return current;
		}
		
		Node pNode = temp.parent;
		while (pNode != null && temp == pNode.right) {
			temp = pNode;
			pNode = pNode.parent;
		}
		return pNode;
	}

	public static void main(String[] args) {
		Successor tree = new Successor();
		Node root = null, temp = null, successor = null;
		root = tree.insert(root, 20);
		root = tree.insert(root, 8);
		root = tree.insert(root, 22);
		root = tree.insert(root, 4);
		root = tree.insert(root, 12);
		root = tree.insert(root, 10);
		root = tree.insert(root, 14);
		temp = root.left.right.right;
		successor = tree.inOrderSuccessor(root, temp);
		if (successor != null) {
			System.out.println("Inorder successor of " + temp.data + " is " + successor.data);
		} else {
			System.out.println("Inorder successor does not exist");
		}
	}

}
