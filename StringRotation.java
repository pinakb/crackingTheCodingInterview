package com.java.code.roop;

import java.util.Scanner;

public class StringRotation {

	public static void main(String[] args) {
		Scanner myObj = null;
		try {
			myObj = new Scanner(System.in);
			System.out.println("String1: ");
			String string1 = myObj.nextLine();

			System.out.println("String2: ");
			String string2 = myObj.nextLine();

			String string3 = string1 + string1;
			boolean rota = string3.contains(string2);
			if (rota && string1.length() == string2.length())
				System.out.println("Strings are rotation of each other.");
			else
				System.out.println("Strings are not rotation of each other.");
		} finally {
			myObj.close();
		}
	}

}
