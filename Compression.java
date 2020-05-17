package com.java.code.roop;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Compression {

	public static void main(String[] args) {
		Scanner myObj = null;
		try {
			myObj = new Scanner(System.in);
			System.out.println("String1: ");
			String string1 = myObj.nextLine();
			StringBuffer finalStr = new StringBuffer();
			String[] strArr = string1.split("");
			Set<String> strSet = new HashSet<String>();
			int count = 0;

			for (int i = 0; i < (string1.length() - 1); i++) {
				strSet.add(strArr[i]);
				count++;
				if (!(strArr[i].equals(strArr[i + 1]))) {
					finalStr.append(strArr[i]).append(count);
					count = 0;
				}
			}
			if (count > 0)
				finalStr.append(strArr[string1.length() - 1]).append(++count);

			int setLength = strSet.size();
			int minCompression = setLength * 2;

			if (string1.length() == minCompression)
				System.out.println("Compression not allowed" + string1);
			else
				System.out.println("Compressed : " + finalStr);
		} finally {
			myObj.close();
		}
	}
}
