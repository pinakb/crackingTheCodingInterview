package com.java.code.roop.three;

import java.util.LinkedList;
import java.util.Stack;

public class StackOfPlates {

	int stackSize = 3;
    private LinkedList<Stack<Integer>> stacks = new LinkedList<Stack<Integer>>();

    public void push(int item) {
        if (stacks.isEmpty() || stacks.getLast().size() >= stackSize) {
            Stack<Integer> stack = new Stack<Integer>();
            stack.push(item);
            stacks.add(stack);
        } else {
            stacks.getLast().push(item);
        }
    }

    public Integer pop() {
        if (stacks.isEmpty())
            System.out.println("Set of Stacks are empty!");
        Stack<Integer> last = stacks.getLast();
        int item = last.pop();
        if (last.isEmpty())
            stacks.removeLast();
        return item;
    }

    public Integer popAt(int index) {
        if (stacks.isEmpty())
        	System.out.println("Set of Stacks are empty!");
        if (index < 0 || index >= stacks.size())
        	System.out.println("Invalid index!");
        int item = stacks.get(index).pop();
        for (int i = index; i < stacks.size() - 1; ++i) {
            Stack<Integer> curr = stacks.get(i);
            Stack<Integer> next = stacks.get(i + 1);
            curr.push(next.remove(0));
        }
        if (stacks.getLast().isEmpty())
            stacks.removeLast();
        return item;
    }

    public void printSetOfStacks() {
        for (Stack<Integer> stack : stacks) {
            for (int item : stack)
                System.out.println(item + " ");
            System.out.println("[TOP]");
        }
    }

    public static void main(String[] args) {
        StackOfPlates setOfStacks = new StackOfPlates();
        setOfStacks.push(1); setOfStacks.push(2); setOfStacks.push(3);
        setOfStacks.push(4); setOfStacks.push(5); setOfStacks.push(6);
        setOfStacks.push(7); setOfStacks.push(8); setOfStacks.push(9);
        setOfStacks.printSetOfStacks();
        System.out.println();
        setOfStacks.pop();
        setOfStacks.printSetOfStacks();
        System.out.println();
        setOfStacks.popAt(1);
        setOfStacks.printSetOfStacks();
        System.out.println();
        setOfStacks.pop();
        setOfStacks.printSetOfStacks();
        System.out.println();
        setOfStacks.popAt(0);
        setOfStacks.printSetOfStacks();
    }
}