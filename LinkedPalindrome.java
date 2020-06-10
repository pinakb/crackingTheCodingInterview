package com.java.code.roop.two;

import java.util.Stack;

public class LinkedPalindrome {

	public static void main(String[] args) {
		SLLNode	node = new SLLNode(1);
		SLLNode	node1 = new SLLNode(2);
		SLLNode	node2 = new SLLNode(3);
		SLLNode	node3 = new SLLNode(4);
		SLLNode	node4 = new SLLNode(3);
		SLLNode	node5 = new SLLNode(2);
		SLLNode	node6 = new SLLNode(6);
		
		node.next = node1;
		node1.next = node2;
		node2.next = node3;
		node3.next = node4;
		node4.next = node5;
		node5.next = node6;
			
		boolean condition = isPalindrome(node);
		System.out.println("IsPalindrome - " + condition);
	}

	private static boolean isPalindrome(SLLNode head) {
		SLLNode slow = head;
		boolean ispalin = true;
		Stack<Object> stack = new Stack<Object>();
		while (slow != null) {
			stack.push(slow.data);
			slow = slow.next; 
		}
		while (head != null) {
			Object i = stack.pop();
			if (i == head.data)
				ispalin = true;
			else {
				ispalin = false;
				break;
			}
			head = head.next;
		}
		return ispalin;
	}
}

class SLLNode {
	Object data;
	SLLNode next;

	public SLLNode(Object data) {
		this.data = data;
		this.next = null;
	}
}
