package com.java.code.roop.two;

import java.util.Scanner;

public class DeleteMiddle {

	public static void main(String[] args) {
		Scanner myObj = null;
		try {
			myObj = new Scanner(System.in);
			System.out.println("Size of Linked List: ");
			String string1 = myObj.nextLine();
			int size = Integer.parseInt(string1);
			SinglyLinkedList sLL = new SinglyLinkedList();
			for (int i = 0; i < size; i++) {
				System.out.println("Enter element " + i);
				String string2 = myObj.nextLine();
				sLL.addNode(string2);
			}
			System.out.println("Enter element to delete: ");
			String string3 = myObj.nextLine();

			Node delNode = new Node(string3);
			if (delNode.getData().equals(sLL.head.getData()) || delNode.getData().equals(sLL.tail.getData()))
				System.out.println("Invalid Position");
			else {
				Node node = sLL.head.getNext();
				for (int i = 1; i < size - 1; i++) {
					if (node.getData().equals(delNode.getData()))
						break;
					else
						node = node.getNext();
				}
				node.setData(node.getNext().getData());
				node.setNext(node.getNext().getNext());
				System.out.println("Updated Linked List is ");
				sLL.display();
			}
		} finally {
			myObj.close();
		}
	}
}
