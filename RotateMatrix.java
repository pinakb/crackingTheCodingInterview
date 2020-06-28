package com.java.code.roop.one;

public class RotateMatrix {

	public static void main(String[] args) {

		int m[][] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
		int rowL = m.length;
		int colL = m[0].length;
		int temp = 0;
		printArr(m);
		if (rowL == colL) {
			for (int i = 0; i < rowL / 2; i++) {
				for (int j = i; j < rowL - i - 1; j++) {
					temp = m[i][j];
					m[i][j] = m[j][rowL - i - 1];
					m[j][rowL - i - 1] = m[rowL - i - 1][rowL - j - 1];
					m[rowL - i - 1][rowL - j - 1] = m[rowL - j - 1][i];
					m[rowL - j - 1][i] = temp;
				}
			}
			System.out.println("\nRotated Matrix AntiClockwise - ");
			printArr(m);
		} else
			System.out.println("Invalid matrix");

	}

	private static void printArr(int m[][]) {
		for (int i = 0; i < m.length; i++) {
			System.out.print("\n");
			for (int j = 0; j < m[i].length; j++)
				System.out.print(m[i][j] + " ");
		}
	}
}
