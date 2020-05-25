package com.java.code.roop.three;

public class QueueViaStacks extends QueueStack {
	static int stackSize = 6;

	public QueueViaStacks(int s) {
		super(s);
	}

	public static void main(String[] args) {
		QueueViaStacks stack1 = new QueueViaStacks(stackSize);
		stack1.push(1);
		stack1.push(2);
		stack1.push(3);
		stack1.push(4);
		stack1.push(5);
		stack1.push(6);
		QueueViaStacks stack2 = new QueueViaStacks(stackSize);
		for (int i = 0; i < stackSize; i++) {
			stack2.push(stack1.pop());
		}
	}
}

class QueueStack {
	int stackize;
	int[] stackArray;
	int top;

	public QueueStack(int s) {
		stackize = s;
		stackArray = new int[stackize];
		top = -1;
	}

	public void push(int num) {
		if (isFull())
			System.out.println("Stack is Full");
		else {
			stackArray[++top] = num;
			System.out.println("Pushed - " + num);
		}
	}

	public int pop() {
		int pop = 0;
		if (isEmpty())
			System.out.println("Stack is Empty");
		else {
			pop = stackArray[top--];
			System.out.println("Popped - " + pop);
		}
		return pop;
	}

	public void peek() {
		if (isEmpty()) {
			System.out.println("Stack is Empty");
		}
		int peek = stackArray[top];
		System.out.println("Peeked - " + peek);
	}

	public boolean isEmpty() {
		return (top == -1);
	}

	public boolean isFull() {
		return (top == stackize - 1);
	}
}
