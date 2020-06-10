package com.java.code.roop;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class PalindromePermutation {

	public static void main(String[] args) {
		Scanner myObj = null;
		try {
			myObj = new Scanner(System.in);
			System.out.println("String1: ");
			String string1 = myObj.nextLine();
			String s1 = string1.toLowerCase();

			String[] s1a = s1.split("");
			boolean isPP = checkPermPal(s1a);
			System.out.println("PalindromePermutation - " + isPP);
		} finally {
			myObj.close();
		}
	}

	private static boolean checkPermPal(String[] s1a) {
		boolean foundOdd = false;
		String temp = null;
		int count1 =0;
		Map<String, Integer> permMap = new HashMap<String, Integer>();
		for (int i = 0; i < s1a.length; i++) {
			temp = s1a[i];
			int count = 0;
			for (int j = 0; j < s1a.length; j++) {
				if (s1a[j].equals(temp)) {
					count++;
				}
				permMap.put(s1a[i], count);
			}
		}

        for (String str : permMap.keySet()) {
            int value = permMap.get(str);
            System.out.println("" + str + ":" + value);
            if (value % 2 == 1) {
                if (foundOdd && count1 >=2) {
                    return false;
                }
                count1++;
                foundOdd = true;
            }
        }
        return true;
    }
}
