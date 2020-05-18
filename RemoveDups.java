package com.java.code.roop.two;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class RemoveDups {

	public static void main(String[] args) {
		Scanner myObj = null;
		try {
			myObj = new Scanner(System.in);
			System.out.println("String1: ");
			String string1 = myObj.nextLine().toLowerCase();
			String[] strArr = string1.split("");
			SinglyLinkedList sLL = new SinglyLinkedList();
			for (int i = 0; i < strArr.length; i++) {
				sLL.addNode(strArr[i]);
			}
			sLL.display();
			
			Map<String, Integer> sLLMap = new HashMap<String, Integer>();
			int count = 0;
			for (int i = 0; i < strArr.length; i++) {
				for (int j = 0; j < strArr.length; j++) {
					if (strArr[j].equals(strArr[i]))
						count++;
				}
				sLLMap.put(strArr[i], count);
			}
			
			sLL.head = null;
			sLL.tail = null;
			for(String str : sLLMap.keySet()) {
				sLL.addNode(str);
			}
			sLL.display();
		}finally {
			myObj.close();
		}
	}
}
