package com.java.code.roop.three;

import java.util.Stack;

public class SortStack {

	static Stack<Integer> mainStack = new Stack<Integer>();
	Stack<Integer> finalStack = new Stack<Integer>();

	public static void main(String[] args) {
		SortStack ss = new SortStack();
		mainStack.push(34);
		mainStack.push(3);
		mainStack.push(31);
		mainStack.push(98);
		mainStack.push(23);
		mainStack.push(66);
		System.out.println(mainStack);
		System.out.println(ss.getSortedStack(mainStack));
	}

	public Stack<Integer> getSortedStack(Stack<Integer> mainStack) {
		while (!mainStack.isEmpty()) {
			int tmp = mainStack.peek();
			mainStack.pop();

			while (!finalStack.empty() && finalStack.peek() < tmp) {
				mainStack.push(finalStack.peek());
				finalStack.pop();
			}
			finalStack.push(tmp);
		}
		return finalStack;
	}

}
