package com.java.code.roop;

import java.util.Arrays;
import java.util.Scanner;

public class CheckPermutation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	    Scanner myObj = new Scanner(System.in);
	    System.out.println("String1: ");
	    String string1 = myObj.nextLine();

	    System.out.println("String2: ");
	    String string2 = myObj.nextLine();
	    
	    String s1 = string1.toLowerCase();
	    String s2 = string2.toLowerCase();
	    
	    String[] s1a = s1.split("");
	    String[] s2a = s2.split("");
	    
	    Arrays.sort(s1a);
	    Arrays.sort(s2a);
	    
	    s1=String.join("", s1a);
	    s2=String.join("", s2a);
	    
	    if (s1.equals(s2))
	    	System.out.println("Strings are permutations of each other");
	    else 
	    	System.out.println("Strings are not permutations of each other");

	}

}
