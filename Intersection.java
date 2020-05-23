package com.java.code.roop.two;

public class Intersection {

	public static void main(String[] args) {
		SLNode node = new SLNode(1);
		SLNode node1 = new SLNode(2);
		SLNode node2 = new SLNode(3);

		SLNode node3 = new SLNode(4);
		SLNode node4 = new SLNode(3);
		SLNode node5 = new SLNode(6);

		node.next = node1;
		node1.next = node2;

		node3.next = node4;
		node4.next = node5;
		node5.next = node1;
		node1.next = node5;
		
		if (node.next == node5.next) {
			System.out.println("Linked lists are intersectiing.");
		} else {
			System.out.println("Linked lists are not intersectiing.");
		}
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
