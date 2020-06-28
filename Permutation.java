package com.java.code.roop.one;

import java.util.Scanner;

public class Permutation {

	public static void main(String[] args) {
		Scanner myObj = null;
		try {
			myObj = new Scanner(System.in);
			System.out.println("String1: ");
			String string1 = myObj.nextLine();

			// String str = string1.toLowerCase();
			String str = "ABC";
			int n = str.length();
			Permutation permutation = new Permutation();
			permutation.permute(str, 0, n - 1);
		} finally {
			myObj.close();
		}
	}

	private void permute(String str, int l, int r) {
		System.out.println("In permute " + l + " " + r);
		if (l == r)
			System.out.println(str);
		else {
			for (int i = l; i <= r; i++) {
				str = swap(str, l, i);
				permute(str, l + 1, r);
				str = swap(str, l, i);
			}
		}
	}

	private String swap(String a, int i, int j) {
		char temp;
		char[] charArray = a.toCharArray();
		temp = charArray[i];
		charArray[i] = charArray[j];
		charArray[j] = temp;
		return String.valueOf(charArray);
	}

}