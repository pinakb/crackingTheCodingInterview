package com.java.code.roop.two;

import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Partition {

	public static void main(String[] args) {
		Scanner myObj = null;
		try {
			myObj = new Scanner(System.in);
			System.out.println("Size of Linked List: ");
			String string1 = myObj.nextLine();
			int size = Integer.parseInt(string1);
			List<Integer> sLL = new LinkedList<Integer>();
			for (int i = 0; i < size; i++) {
				System.out.println("Enter element " + i);
				String string2 = myObj.nextLine();
				sLL.add(Integer.parseInt(string2));
			}

			for (int temp : sLL) {
				System.out.println(temp);
			}

			System.out.println("Enter element to pivot for partition: ");
			String string3 = myObj.nextLine();

			int[] listArray = new int[size];
			for (int i = 0; i < size; i++)
				listArray[i] = sLL.get(i);

			Arrays.sort(listArray);

			int index = Arrays.binarySearch(listArray, Integer.parseInt(string3));
			int pivotPosition = (index < 0) ? -1 : index;

			sLL.clear();
			if (pivotPosition == 0 || pivotPosition == size) {
				for (int i = 0; i < size; i++)
					sLL.add(listArray[i]);
			} else {
				for (int j = 0; j < pivotPosition; j++)
					sLL.add(listArray[j]);
				sLL.add(listArray[pivotPosition + 1]);
				sLL.add(listArray[pivotPosition]);
				if (size >= (pivotPosition + 2)) {
					for (int j = pivotPosition + 2; j < size; j++)
						sLL.add(listArray[j]);
				}
			}

			System.out.println("Updated Linked List is " + sLL);
		} finally {
			myObj.close();
		}
	}
}
