package com.java.code.roop;

import java.util.Scanner;

public class URLify {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	    Scanner myObj = new Scanner(System.in);
	    System.out.println("String1: ");
	    String string1 = myObj.nextLine();
	    
	    System.out.println("Length: ");
	    String string2 = myObj.nextLine();
	    
	    String[] strArr = string1.split(" ");
	    string1=String.join("%20", strArr);
	    System.out.println(string1);
	}

}
