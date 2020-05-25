package com.java.code.roop.three;

import java.util.Stack;

public class StackMin extends MinStack {	//extends Stack<Integer> {
/*
	private static final long serialVersionUID = 5348189723673690126L;

	Stack<Integer> min = new Stack<Integer>();

	public void push(int item) {
		if (min.isEmpty() || item < min()) {
			min.push(item);
		}
		super.push(item);
	}

	public Integer pop() {
		int item = super.pop();
		if (item == min()) {
			min.pop();
		}
		return item;
	}

	public Integer min() {
		return min.peek();
	}

	public static void main(String[] args) {
		StackMin stack = new StackMin();
		stack.push(2);
		System.out.println(stack.min());
		stack.push(-1);
		System.out.println(stack.min());
		stack.push(3);
		System.out.println(stack.min());
		stack.push(-10);
		System.out.println(stack.min());
		stack.pop();
		System.out.println(stack.min());
		stack.pop();
		System.out.println(stack.min());
		stack.push(-20);
		System.out.println(stack.min());
		stack.pop();
		System.out.println(stack.min());
	}
}
*/
	public StackMin(int s) {
		super(s);
	}

	public static void main(String[] args) {
		MinStack stack = new MinStack(6);
		stack.push(15);
		stack.push(16);
		System.out.println("Minimum  - " +stack.getMinNum());
		stack.push(10);
		System.out.println("Minimum  - " +stack.getMinNum());
		stack.push(1);
		System.out.println("Minimum  - " +stack.getMinNum());
		stack.push(2);
		System.out.println("Minimum  - " +stack.getMinNum());
	}

}

class MinStack {
	int stackize;
	int[] stackArray;
	int top;
	private int minNum;

	public int getMinNum() {
		return minNum;
	}

	public void setMinNum(int minNum) {
		this.minNum = minNum;
	}

	public MinStack(int s) {
		stackize = s;
		stackArray = new int[stackize];
		top = -1;
	}

	public void push(int num) {
		if (isFull()) {
			System.out.println("Stack is Full");
			return;
		}
		else if (isEmpty()) {
			minNum = num;
			stackArray[++top] = num;
			System.out.println("Pushed - " + num);
			return;
		} else if (num < minNum) {
			stackArray[++top] = ((2*num) - minNum);
			minNum = num;
			System.out.println("Pushed - " + num);
		} else {
			stackArray[++top] = num;
			System.out.println("Pushed - " + num);
		}
	}

	public void pop() {
		if (isEmpty()) {
			System.out.println("Stack is Empty");
			return;
		}
		int pop = stackArray[top--];
		System.out.println("Popping - " + pop);
		if (pop < minNum) {
            System.out.println(minNum);
            minNum = 2*minNum - pop;
		} else
            System.out.println(pop); 
	}

	public void peek() {
		if (isEmpty()) {
			System.out.println("Stack is Empty");
			return;
		}
		int peek = stackArray[top];
		System.out.println("Peeked - " + peek);
		if (peek < minNum) 
            System.out.println(minNum); 
        else
            System.out.println(peek); 
	}

	public boolean isEmpty() {
		return (top == -1);
	}

	public boolean isFull() {
      return (top == stackize - 1);
   }
}
