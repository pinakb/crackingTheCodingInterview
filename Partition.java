package com.java.code.roop.two;

import java.util.Arrays;
import java.util.Scanner;

public class Partition {

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
				sLL.addNode(Integer.parseInt(string2));
			}
			sLL.display();
			System.out.println("Enter element to pivot for partition: ");
			String string3 = myObj.nextLine();
			Node pivotNode = new Node(Integer.parseInt(string3));

			int[] listArray = new int[size];
			listArray[0] = (int) sLL.head.getData();
			Node node = sLL.head.getNext();
			int i = 1;
			while (node.getNext() != null) {
				listArray[i] = (int) node.getData();
				node = node.getNext();
				i++;
			}
			listArray[size-1] = (int) sLL.tail.getData();

			Arrays.sort(listArray);
			
			int index = Arrays.binarySearch(listArray, (int)pivotNode.getData());
			int pivotPosition = (index < 0) ? -1 : index;

			sLL.head = null;
			if (pivotPosition == 0) {
				sLL.head = new Node(pivotNode);
			} else {
				sLL.head = new Node(listArray[0]);
				for (int j = 1; j < pivotPosition; j++)
					sLL.tail.setNext(new Node(listArray[i]));
				if (size == pivotPosition)
					sLL.tail.setNext(new Node(pivotPosition));
				else {
					sLL.tail.setNext(new Node(listArray[pivotPosition+1]));
					sLL.tail.setNext(new Node(listArray[pivotPosition]));
					if (size > (pivotPosition + 2)) {
						for (int j = pivotPosition+2; j<size;j++) {
							sLL.tail.setNext(new Node(listArray[j]));
						}
					}
				}
			}
			
			System.out.println("Updated Linked List is ");
			sLL.display();
		} finally {
			myObj.close();
		}
	}
}
