package com.java.code.roop.four;

import java.util.ArrayList;
import java.util.Random;

public class RandomNode {

	int size;
	ArrayList<Node> nodeArray;
	Random rgen;
	Node root;

	public RandomNode() {
		nodeArray = new ArrayList<Node>();
		rgen = new Random();
	}

	public boolean find(int value) {
		return findHelper(root, value);
	}

	private boolean findHelper(Node n, int value) {
		if (n == null)
			return false;
		if (n.data == value)
			return true;

		if (n.data < value)
			return findHelper(n.left, value);
		else
			return findHelper(n.right, value);
	}

	public void insert(int value) {
		insertHelper(root, value);
	}

	private Node insertHelper(Node n, int value) {
		if (n == null) {
			n = new Node(value);
			nodeArray.add(n);
			size++;
		} else {
			if (value <= n.data)
				n.left = insertHelper(n.left, value);
			else
				n.right = insertHelper(n.right, value);
		}
		return n;
	}

	//In-order successor of ROOT.
	private Node getSuccessor(Node root) {
		if (root == null || root.right == null)
			return null;

		Node n = root.right;
		while (n.left != null) {
			n = n.left;
		}
		return n;
	}

	private Node getRandomNode() {
		Node n = nodeArray.get(rgen.nextInt(nodeArray.size()));
		return n;
	}

	public static void main(String args[]) {

		Node ranNode = null;
		Node root = new Node(10);
		root.left = new Node(20);
		root.right = new Node(30);
		root.left.left = new Node(40);
		root.left.right = new Node(50);
		root.right.left = new Node(60);

		RandomNode bstTree = new RandomNode();
		bstTree.insert(10);
		bstTree.insert(20);
		bstTree.insert(30);
		bstTree.insert(40);
		bstTree.insert(50);
		bstTree.insert(60);
		bstTree.root = root;
		ranNode = bstTree.getRandomNode();
		System.out.println("A Random Node From Tree : " + ranNode.data);
		ranNode = bstTree.getRandomNode();
		bstTree.insert(70);
		System.out.println("Get Successor of 10 : " + bstTree.getSuccessor(root).data);
		System.out.println("A Random Node From Tree : " + ranNode.data);
		bstTree.insert(80);
		System.out.println("Get Successor of 30 : " + bstTree.getSuccessor(root.right).data);
		ranNode = bstTree.getRandomNode();
		System.out.println("A Random Node From Tree : " + ranNode.data);
	}
}
