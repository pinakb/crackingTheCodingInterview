package com.java.code.roop.four;

class STNode extends Node {
	int data;
	STNode nextRight;

	STNode(int item) {
		super(item);
		nextRight = null;
	}
}

class CheckSubTree {
	STNode root1, root2;

	/*
	 * A utility function to check whether trees with roots as root1 and root2 are
	 * identical or not
	 */
	boolean areIdentical(Node root1, Node root2) {

		/* base cases */
		if (root1 == null && root2 == null)
			return true;

		if (root1 == null || root2 == null)
			return false;

		return (root1.data == root2.data && areIdentical(root1.left, root2.left)
				&& areIdentical(root1.right, root2.right));
	}

	boolean isSubtree(Node tree, Node subTree) {
		if (subTree == null) return true;
		if (tree == null) return false;
		if (areIdentical(tree, subTree))
			return true;

		return isSubtree(tree.left, subTree) || isSubtree(tree.right, subTree);
	}

	public static void main(String args[]) {
		CheckSubTree tree = new CheckSubTree();

		tree.root1 = new STNode(26);
		tree.root1.right = new STNode(3);
		tree.root1.right.right = new STNode(3);
		tree.root1.left = new STNode(10);
		tree.root1.left.left = new STNode(4);
		tree.root1.left.left.right = new STNode(30);
		tree.root1.left.right = new STNode(6);

		tree.root2 = new STNode(10);
		tree.root2.right = new STNode(6);
		tree.root2.left = new STNode(4);
		tree.root2.left.right = new STNode(30);
		tree.root2.left.right.right = new STNode(1);

		if (tree.isSubtree(tree.root1, tree.root2))
			System.out.println("Tree 2 is subtree of Tree 1 ");
		else
			System.out.println("Tree 2 is not a subtree of Tree 1");
	}
}
