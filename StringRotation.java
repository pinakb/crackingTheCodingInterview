package com.java.code.roop.one;

import java.util.Arrays;
import java.util.Scanner;

public class StringRotation {

	public static void main(String[] args) {
		Scanner myObj = null;
		try {
			myObj = new Scanner(System.in);
			System.out.println("String1: ");
			String string1 = myObj.nextLine();
			String s1 = string1.toLowerCase();

			System.out.println("String2: ");
			String string2 = myObj.nextLine();
			String s2 = string2.toLowerCase();

			String string3 = string1 + string1;
			boolean rota = string3.contains(string2);
			if (rota && string1.length() == string2.length())
				System.out.println("Strings are rotation of each other.");
			else
				System.out.println("Strings are not rotation of each other.");

			// Local Alignment
			int gap = 0, mismatch = 0, match = 1;

			int[][] opt = new int[s1.length() + 1][s2.length() + 1];

			for (int i = 1; i <= s1.length(); i++)
				opt[i][0] = opt[i - 1][0] + gap;
			for (int j = 1; j <= s2.length(); j++)
				opt[0][j] = opt[0][j - 1] + gap;

			for (int i = 1; i <= s1.length(); i++) {
				for (int j = 1; j <= s2.length(); j++) {
					int scoreDiag = opt[i - 1][j - 1] + (s1.charAt(i - 1) == s2.charAt(j - 1) ? match : mismatch);
					int scoreLeft = opt[i][j - 1] + gap;
					int scoreUp = opt[i - 1][j] + gap;

					opt[i][j] = Math.max(Math.max(scoreDiag, scoreLeft), scoreUp);
				}
			}

			for (int i = 0; i <= s1.length(); i++) {
				for (int j = 0; j <= s2.length(); j++)
					System.out.print(opt[i][j] + "\t");
				System.out.println();
			}

			int i = s1.length();
			int j = s2.length();
			StringBuilder sb = new StringBuilder();;
			while (i > 0 && j > 0) {
				if (opt[i][j] == opt[i][j-1])
					System.out.println("Do Nothing");
				else {
					sb.append(s2.charAt(opt[i][j - 1]));
				}
				j--;
			}
			
			
			System.out.println("Is a rotation, Common String : " + sb.reverse());

		} finally {
			myObj.close();
		}
	}

}
