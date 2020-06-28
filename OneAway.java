package com.java.code.roop.one;

import java.util.Arrays;
import java.util.Scanner;

public class OneAway {

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
//			boolean edit = isOneEdit(s1, s2);
//			if (edit)
			
			//Global Alignment 1
			
			int gap = 1, mismatch = 1, match = 0;

			int[][] opt = new int[s1.length() + 1][s2.length() + 1];

			for (int i = 1; i <= s1.length(); i++)
			    opt[i][0] = opt[i - 1][0] + gap;
			for (int j = 1; j <= s2.length(); j++)
			    opt[0][j] = opt[0][j - 1] + gap;

			for (int i = 1; i <= s1.length(); i++) {
			    for (int j = 1; j <= s2.length(); j++) {
			        int scoreDiag = opt[i - 1][j - 1] + (s1.charAt(i-1) == s2.charAt(j-1) ? match : mismatch);
			        int scoreLeft = opt[i][j - 1] + gap;
			        int scoreUp = opt[i - 1][j] + gap;

			        opt[i][j] = Math.min(Math.min(scoreDiag, scoreLeft), scoreUp);
			    }
			}

			for (int i = 0; i <= s1.length(); i++) {
			    for (int j = 0; j <= s2.length(); j++)
			        System.out.print(opt[i][j] + "\t");
			    System.out.println();
			}

//Global Alignment 2
/*			int dist = getDist(s1, s2);
			if (dist <= 1)
*/
			if(opt[s1.length()-1][s2.length()-1] <= 1)
				System.out.println("Strings are one distance away.");
			else
				System.out.println("Strings are more than one distance away.");
		} finally {
			myObj.close();
		}
	}

/*
	 private static boolean isOneEdit(String s1, String s2) {
		if (s1.equals(s2))
			System.out.println("Strings are same. Invalid inputs.");

		int l1 = s1.length(), l2 = s2.length();
		if ((l1 - l2) > 1 || (l2 - l1) > 1) {
			return false;
		}

		int i = 0, j = 0;
		int diff = 0;
		while (i < l1 && j < l2) {
			char c1 = s1.charAt(i);
			char c2 = s2.charAt(j);
			if (c1 != c2) {
				diff++;
				if (l1 > l2)
					i++;
				if (l2 > l1)
					j++;
				if (l1 == l2) {
					i++;
					j++;
				}
			} else {
				i++;
				j++;
			}
			if (diff > 1) {
				return false;
			}
		}
		
		if (diff == 1 && l1 != l2 && (i != l1 || j != l2))
			return false;

		return true;
	 */

	//Global Alignment 2
	
/*	private static int getDist(String s1, String s2) {
		int s1l = s1.length();
		int s2l = s2.length();
		int[][] gAMatrix = new int[s1l][s2l];
		for (int[] arr : gAMatrix) {
			Arrays.fill(arr, -1);
		}
		return calDist(s1, s2, gAMatrix, s1l - 1, s2l - 1);
	}

	private static int calDist(String s1, String s2, int[][] gAMatrix, int i, int j) {
		if (i < 0) {
			return j + 1;
		} else if (j < 0) {
			return i + 1;
		}
		if (gAMatrix[i][j] != -1) {
			return gAMatrix[i][j];
		}
		if (s1.charAt(i) == s2.charAt(j)) {
			gAMatrix[i][j] = calDist(s1, s2, gAMatrix, i - 1, j - 1);
		} else {
			int prevMin = Math.min(calDist(s1, s2, gAMatrix, i, j - 1), calDist(s1, s2, gAMatrix, i - 1, j));
			prevMin = Math.min(prevMin, calDist(s1, s2, gAMatrix, i - 1, j - 1));
			gAMatrix[i][j] = 1 + prevMin;
		}
		return gAMatrix[i][j];
	}
	*/
}
