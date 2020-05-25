package com.java.code.roop.three;

public class ThreeInOne {

	int numStacks = 3;
	int stackSize;
	private int[] values;
	private int[] sizes;

	public ThreeInOne(int stackSize) {
		this.stackSize = stackSize;
		values = new int[stackSize * numStacks];
		sizes = new int[numStacks];
	}

	public void push(int stackNum, int value) {
		if (sizes[stackNum] == stackSize)
			System.out.println("<<<<<< Stack is full >>>>>>");
		sizes[stackNum]++;
		values[topIndex(stackNum)] = value;
	}

	public int pop(int stackNum) {
		if (sizes[stackNum] == 0)
			System.out.println("<<<<<< Stack is empty >>>>>>");
		int value = values[topIndex(stackNum)];
		values[topIndex(stackNum)] = 0;
		sizes[stackNum]--;
		return value;
	}

	public int peek(int stackNum) {
		if (sizes[stackNum] == 0)
			System.out.println("<<<<<< Stack is empty >>>>>>");
		int top = values[topIndex(stackNum)];
		return top;
	}

	public int topIndex(int stackNum) {
		int index = stackNum * stackSize;
		int size = sizes[stackNum];
		int topIndex = index + size - 1;
		return topIndex;

	}

	public static void main(String[] args) {
		ThreeInOne stacks = new ThreeInOne(4);
		stacks.push(0, 1);
		stacks.push(0, 2);
		stacks.push(0, 3);
		stacks.push(0, 4);
		stacks.push(1, 5);
		stacks.push(1, 6);
		stacks.push(1, 7);
		stacks.push(1, 8);
		stacks.push(2, 9);
		stacks.push(2, 10);
		stacks.push(2, 11);
		stacks.push(2, 12);
		System.out.println("Peeking at 1st stack " + stacks.peek(0));
		System.out.println("Peeking at 2nd stack " + stacks.peek(1));
		System.out.println("Peeking at 3rd stack " + stacks.peek(2));
		System.out.println("Pop at 3 : " + stacks.pop(2));
		System.out.println("Pop at 3 : " + stacks.pop(2));
		System.out.println("Pop at 1 : " + stacks.pop(0));
		System.out.println("Pop at 2 : " + stacks.pop(1));
		System.out.println("Peeking at 1st stack " + stacks.peek(0));
		System.out.println("Peeking at 2nd stack " + stacks.peek(1));
		System.out.println("Peeking at 3rd stack " + stacks.peek(2));
		stacks.push(1, 15);
		stacks.push(2, 19);
		System.out.println("Peeking at 1st stack " + stacks.peek(0));
		System.out.println("Peeking at 2nd stack " + stacks.peek(1));
		System.out.println("Peeking at 3rd stack " + stacks.peek(2));
	}

}
