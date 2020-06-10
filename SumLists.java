package com.java.code.roop.two;

import java.util.LinkedList;
import java.util.List;

public class SumLists {

	public static void main(String[] args) {
		List<Integer> aList = new LinkedList<Integer>();
		aList.add(7);
		aList.add(1);
		aList.add(6);
		StringBuilder asb = new StringBuilder();
		asb.append(aList.get(0)).append(aList.get(1)).append(aList.get(2));
		asb.reverse();
		int aNum = Integer.parseInt(asb.toString());

		List<Integer> bList = new LinkedList<Integer>();
		bList.add(5);
		bList.add(9);
		bList.add(2);
		StringBuilder bsb = new StringBuilder();
		bsb.append(bList.get(0)).append(bList.get(1)).append(bList.get(2));
		bsb.reverse();
		int bNum = Integer.parseInt(bsb.toString());

		int result = aNum + bNum;
		StringBuilder resStrb = new StringBuilder();
		String resStr = String.valueOf(result);
		resStrb.append(resStr).reverse();
		String[] resArr = resStrb.toString().split("");
		List<String> resList = new LinkedList<String>();
		for (int i = 0 ;i<resStrb.length();i++) {
			resList.add(resArr[i]);
		}
		System.out.println(result);
		System.out.println(resList);
	}
}
