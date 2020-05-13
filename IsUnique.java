package com.java.code.roop;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class IsUnique {
	public static void main (String args[]) {
	    Scanner myObj = new Scanner(System.in);
	    System.out.println("String1: ");
	    String string1 = myObj.nextLine();
	    System.out.println("String1 is: " + string1);
	   
	    String str1 = string1.toLowerCase();
	    
	    Set<Character> stringSet = new HashSet<Character>(); 
	    for (int i=0;i<str1.length();i++) {
		    stringSet.add(str1.charAt(i));
	    }
	    
	    if (str1.length() == stringSet.size())
	    	System.out.println("The string has unique characters.");
	    else
	    	System.out.println("The string does not has unique characters.");
	}
}
