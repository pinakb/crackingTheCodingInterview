package com.java.code.roop.two;

//A node of the singly linked list    
class Node{    
    private Object data;    
	private Node next;    
    
    public Node(Object data) {    
        this.data = data;    
        this.next = null;    
    }   

    public Object getData() {
		return data;
	}

	public void setData(Object data) {
		this.data = data;
	}

	public Node getNext() {
		return next;
	}

	public void setNext(Node next) {
		this.next = next;
	}

}    

public class SinglyLinkedList {    
	
    //The head and tail of the singly linked list    
    public Node head = null;    
    public Node tail = null;    
        
    public void addNode(Object data) {    

    	Node newNode = new Node(data);    
            
        if(head == null) {    
            head = newNode;    
            tail = newNode;    
        }    
        else {    
            tail.setNext(newNode);    
            tail = newNode;    
        }    
    }    
        
    public void display() {    
        Node current = head;    
        if(head == null) {    
            System.out.println("List is empty");    
            return;    
        }    
        System.out.println("Nodes of singly linked list: ");    
        while(current != null) {    
            System.out.print(current.getData() + " ");    
            current = current.getNext();    
        }    
        System.out.println();    
    }    
        
    public static void main(String[] args) {    
        SinglyLinkedList sList = new SinglyLinkedList();    
        sList.addNode(1);    
        sList.addNode(2);    
        sList.addNode(3);    
        sList.addNode(4);    
        sList.display();    
    }    
}    