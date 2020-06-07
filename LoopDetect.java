package com.java.code.roop.two;

import java.util.HashSet;
import java.util.Set;

public class LoopDetect {

	public static void main(String[] args) {
		SLNode node = new SLNode("A");
		SLNode node1 = new SLNode("B");
		SLNode node2 = new SLNode("C");
		SLNode node3 = new SLNode("D");
		SLNode node4 = new SLNode("E");

		node.next = node1;
		node1.next = node2;
		node2.next = node3;
		node3.next = node4;
		node4.next = node2;

		SLNode loopNode = findLoopNode(node);
		System.out.println("Loop node - " + loopNode.data);
	}
	
	private static SLNode findLoopNode (SLNode node) {
		Set<SLNode> nodeSet = new HashSet<SLNode>();
		while (node.next != null) {
			if (nodeSet.contains(node))
				return node;
			nodeSet.add(node);
			node = node.next;
		}
		return node;
	}

}
