package com.java.code.roop.two;

import java.util.Scanner;

public class KToLast {

	public static void main(String[] args) {
		Scanner myObj = null;
		try {
			myObj = new Scanner(System.in);
			System.out.println("Size of Linked List: ");
			String string1 = myObj.nextLine();
			SinglyLinkedList sLL = new SinglyLinkedList();
			for (int i = 0; i < Integer.parseInt(string1); i++) {
				System.out.println("Enter element " + i);
				Object string2 = myObj.nextLine();
				sLL.addNode(string2);
			}
			System.out.println("Enter Kth position from last: ");
			String string3 = myObj.nextLine();
			int actualPosition = Integer.parseInt(string1) - Integer.parseInt(string3);
			if (actualPosition == 0)
				System.out.println(sLL.head);
			else {
				Node node = sLL.head;
				for (int i = 0; i < actualPosition; i++) {
					node = node.getNext();
				}
				System.out.println("Kth element from last is : " + node.getData());
			}
			sLL.display();
		} finally {
			myObj.close();
		}
	}
}
