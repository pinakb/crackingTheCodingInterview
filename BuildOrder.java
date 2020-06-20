package com.java.code.roop.four;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Project {

	private ArrayList<Project> children = new ArrayList<>();
	private String name;
	private int dependencies = 0;

	public Project(String n) {
		name = n;
	}

	@Override
	public String toString() {
		return name;
	}
	
	public String getName() {
		return name;
	}

	public int getDependencies() {
		return dependencies;
	}

	public void incrementDependencies() {
		dependencies++;
	}

	public void decrementDependencies() {
		dependencies--;
	}

	public void addNeighbour(Project node) {
		children.add(node);
		node.incrementDependencies();
	}

	public ArrayList<Project> getChildren() {
		return children;
	}

}

class Graph {
	
	private ArrayList<Project> nodes = new ArrayList<Project>();
	private HashMap<String, Project> map = new HashMap<String, Project>();

	public Project getOrCreateNode(String name) {
		if (!map.containsKey(name)) {
			Project node = new Project(name);
			nodes.add(node);
			map.put(name, node);
		}
		return map.get(name);
	}

	public void addEgde(String dependenton, String dependent) {
		Project end = getOrCreateNode(dependenton);
		Project start = getOrCreateNode(dependent);
		end.addNeighbour(start);
	}

	public ArrayList<Project> getNodes() {
		return nodes;
	}
}

public class BuildOrder {
	
	public List<Project> findBuildOrder(String[] projects, String[][] dependencies) {
		Graph graph = buildGraph(projects, dependencies);
		return orderProjects(graph.getNodes());
	}

	private List<Project> orderProjects(ArrayList<Project> projects) {

		List<Project> order = new ArrayList<Project>();
		int endOfList = addNonDependent(order, projects, 0);
		int toBeProcessed = 0;

		while (toBeProcessed < projects.size()) {
			Project current = (Project) order.get(toBeProcessed);

			if (current == null) return null;
			
			ArrayList<Project> children = current.getChildren();
			for (Project child : children)
				child.decrementDependencies();
			
			endOfList = addNonDependent(order, projects, endOfList);
			toBeProcessed++;
		}

		return order;
	}

	private int addNonDependent(List<Project> order, ArrayList<Project> projects, int offset) {
		for (Project project : projects) {
			if (project.getDependencies() == 0 && !order.contains(project)) {
				order.add(offset, project);
				offset++;
			}
		}
		return offset;
	}

	private Graph buildGraph(String[] projects, String[][] dependencies) {
		Graph graph = new Graph();
		for (String project : projects) {
			graph.getOrCreateNode(project);
		}

		for (String[] dependency : dependencies) {
			String dependenton = dependency[0];
			String dependent = dependency[1];
			graph.addEgde(dependenton, dependent);
		}

		return graph;
	}

	public static void main(String[] args) {
		String[] projects = { "a", "b", "c", "d", "e", "f" };
		String[][] dependencies = { { "a", "d" }, { "f", "b" }, { "b", "d" }, { "f", "a" }, { "d", "c" } };

		BuildOrder buildOrder = new BuildOrder();
		List<Project> order = buildOrder.findBuildOrder(projects, dependencies);
		System.out.println(order);

	}

}