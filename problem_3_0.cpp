//Implementing Stack class using linked list
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next = NULL;

};

class myStack
{
    public:
        //variable declaration
        node* top = NULL;
        int minValue=0;

        //Method Prototypes
        void push(int d);
        node* pop();
        node* peek();
        bool isEmpty();
};

void myStack::push(int d)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = d;
    newNode->next = top;
    top= newNode;
}

node* myStack::pop()
{
    if(top== NULL)
    {
        return NULL;
    }
    else
    {
        node* returnNode = top;
        top = top->next;
        returnNode->next = NULL;
        return returnNode;
    }

}

node* myStack::peek()
{
    if(top== NULL)
    {
        cout<<"Stack is empty";
        return NULL;
    }
    else
    {
        return top;
    }
}

bool myStack::isEmpty()
{
    return top == NULL;
}

class myQueue
{
    public:
        //variables
        node* first= NULL;
        node* last=  NULL;
        // function prototypes
        void add(int item);
        node* removeItem();
        node* peek();
        bool isEmpty();

};

void myQueue::add(int item)
{
    if(first==NULL)
    {
        node* newNode = (node*) malloc(sizeof(node));
        newNode->data= item;
        first=newNode;
        last= newNode;
    }
    else
    {
        node* newNode = (node*) malloc(sizeof(node));
        newNode->data= item;
        last->next = newNode;
        last = last->next;
    }
}

node* myQueue::removeItem()
{
    if(first!= NULL)
    {
        node* returnNode = first;
        first = first->next;
        return returnNode;
    }
    else
        return NULL;

}

node* myQueue::peek()
{
    if(first==NULL)
    {
        return NULL;
    }
    else
    {
        return first;
    }
}

bool myQueue::isEmpty()
{
    if(first== NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout<<"Sample input is 1,2,3"<<endl;
    //Stack Operations
    cout<<"stack operations."<<endl;
    myStack m;
    m.push(1);
    m.push(2);
    m.push(3);
    node* pTop = m.peek();
    cout<<"Peek: "<<pTop->data<<endl;
    node* popped = m.pop();
    cout<<"popped: "<<popped->data<<endl;
    pTop = m.peek();
    cout<<"new Peek: "<<pTop->data<<endl;

    //Queue Operations
    cout<<"\nqueue operations."<<endl;
    myQueue q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);
    node* qFirst = q.peek();
    cout<<"first in queue: "<<qFirst->data<<endl;
    node* rItem= q.removeItem();
    cout<<"Item Removed: "<<rItem->data<<endl;
    qFirst= q.peek();
    cout<<"first in queue: "<<qFirst->data<<endl;

}
