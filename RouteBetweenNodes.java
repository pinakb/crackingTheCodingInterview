package com.java.code.roop.four;

import java.util.Iterator;
import java.util.LinkedList;

class RouteBetweenNodes {
	private int size;
	private LinkedList<Integer> adj[];

	RouteBetweenNodes(int size) {
		this.size = size;
		adj = new LinkedList[size];
		for (int i = 0; i < size; ++i)
			adj[i] = new LinkedList();
	}

	void addEdge(int v, int w) {
		adj[v].add(w);
	}

	Boolean isReachable(int s, int d) {
		boolean visited[] = new boolean[size];
		LinkedList<Integer> queue = new LinkedList<Integer>();
		visited[s] = true;
		queue.add(s);
		Iterator<Integer> i;
		while (queue.size() != 0) {
			s = queue.poll();
			int n;
			i = adj[s].listIterator();
			while (i.hasNext()) {
				n = i.next();
				if (n == d)
					return true;
				if (!visited[n]) {
					visited[n] = true;
					queue.add(n);
				}
			}
		}
		return false;
	}

	public static void main(String args[]) {
		RouteBetweenNodes g = new RouteBetweenNodes(4);
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 2);
		g.addEdge(2, 0);
		g.addEdge(2, 3);
		g.addEdge(3, 3);

		int u = 1;
		int v = 3;
		if (g.isReachable(u, v))
			System.out.println("There is a path from " + u + " to " + v);
		else
			System.out.println("There is no path from " + u + " to " + v);

		u = 3;
		v = 1;
		if (g.isReachable(u, v))
			System.out.println("There is a path from " + u + " to " + v);
		else
			System.out.println("There is no path from " + u + " to " + v);
	}
}