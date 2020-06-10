package com.java.code.roop;

import java.util.Scanner;

public class URLify {

	public static void main(String[] args) {
		Scanner myObj = null;
		try {
			myObj = new Scanner(System.in);
			System.out.println("String1: ");
			String string1 = myObj.nextLine();

			String[] strArr = string1.split(" ");
			string1 = String.join("%20", strArr);
			System.out.println(string1);
		} finally {
			myObj.close();
		}
	}

}