package com.java.code.roop.three;

import java.util.Stack;

public class QueueViaStacks extends QueueStack {

	public static void main(String[] args) {
		QueueViaStacks stackQueue = new QueueViaStacks();
		stackQueue.enqueue(1);
		stackQueue.enqueue(2);
		stackQueue.enqueue(3);
		System.out.println(stackQueue.dequeue());
		stackQueue.enqueue(4);
		stackQueue.enqueue(5);
		stackQueue.enqueue(6);
		System.out.println(stackQueue.dequeue());
		System.out.println(stackQueue.dequeue());
	}
}

class QueueStack {
	Stack<Integer> s1 = new Stack<Integer>();
	Stack<Integer> s2 = new Stack<Integer>();

	public void enqueue(int num) {
		while (!s1.isEmpty())
			s2.push(s1.pop());

		s1.push(num);

		while (!s2.isEmpty())
			s1.push(s2.pop());
	}

	public int dequeue() {
		if (s1.isEmpty()) {
			System.out.println("Queue is Empty");
			System.exit(0);
		}

		int num = s1.peek();
		s1.pop();
		return num;
	}
}