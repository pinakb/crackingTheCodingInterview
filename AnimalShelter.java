package com.java.code.roop.three;

import java.util.LinkedList;

public class AnimalShelter {

	int counter;
	LinkedList<Integer> cats;
	LinkedList<Integer> dogs;

	public AnimalShelter() {
		cats = new LinkedList<Integer>();
		dogs = new LinkedList<Integer>();
	}

	public void enqueue(Animal animal) {
		switch (animal.type) {
		case "dog":
			dogs.add(counter);
			counter++;
			break;
		case "cat":
			cats.add(counter);
			counter++;
			break;
		}
	}

	public Integer dequeueCat() {
		if (cats.isEmpty()) {
			System.out.println("No cats found.");
			System.exit(0);
		}
		System.out.println("Cat");
		return cats.pop();
	}

	public Integer dequeueDog() {
		if (dogs.isEmpty()) {
			System.out.println("No dogs found.");
			System.exit(0);
		}
		System.out.println("Dog");
		return dogs.pop();
	}

	public Integer dequeueAny() {
		if (dogs.isEmpty() && cats.isEmpty()) {
			System.out.println("No cats or dogs found.");
			System.exit(0);
		}
		if (dogs.isEmpty()) {
			System.out.println("Cat");
			return cats.pop();
		} else if (cats.isEmpty()) {
			System.out.println("Dog");
			return dogs.pop();
		} else {
			if (cats.peek() < dogs.peek()) {
				System.out.println("Cat");
				return cats.pop();
			} else {
				System.out.println("Dog");
				return dogs.pop();
			}
		}
	}
	
	public static void main (String[] args ) {
		AnimalShelter catDog = new AnimalShelter();
		catDog.enqueue(new Cat());
		catDog.enqueue(new Dog());
		catDog.enqueue(new Cat());
		catDog.enqueue(new Cat());
		catDog.enqueue(new Dog());
		catDog.enqueue(new Dog());
		catDog.enqueue(new Cat());
		System.out.println(catDog.dequeueAny());
		System.out.println(catDog.dequeueCat());
		System.out.println(catDog.dequeueDog());
		System.out.println("Cats - " + catDog.cats.size());
		System.out.println("Dogs - " + catDog.dogs.size());
	}
}

class Animal {
	String type;
}

class Dog extends Animal {
	Dog() {
		super();
		type = "dog";
	}
}

class Cat extends Animal {
	Cat() {
		super();
		type = "cat";
	}
}