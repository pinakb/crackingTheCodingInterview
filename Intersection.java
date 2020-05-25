package com.java.code.roop.two;

public class Intersection {

	public static void main(String[] args) {
		SLNode node = new SLNode(1);
		SLNode node1 = new SLNode(2);
		SLNode node2 = new SLNode(3);

		SLNode node3 = new SLNode(4);
		SLNode node4 = new SLNode(3);
		SLNode node5 = new SLNode(6);

		SLNode intersect = node1;
		
		node.next = intersect;
		node1.next = node2;
		node2.next = null;

		node3.next = node4;
		node4.next = intersect;
		intersect.next = node5;
		node5.next = null;

		boolean isIntersecting = isIntersecting (node, node3);
		if (isIntersecting)
			System.out.println("Linked lists are intersectiing.");
		else
			System.out.println("Linked lists are not intersectiing.");
	}
	
	private static boolean isIntersecting(SLNode nodeOne, SLNode nodeTwo) {
		while (nodeOne.next != null) {
			while (nodeTwo.next != null) {
				if (nodeOne.next == nodeTwo.next)
					return true;
				nodeTwo = nodeTwo.next;
			}
			nodeOne = nodeOne.next;
		}
		return false;
	}

}

class SLNode {
	Object data;
	SLNode next;

	public SLNode(Object data) {
		this.data = data;
		this.next = null;
	}
}
