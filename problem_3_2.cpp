//Implementing min function for stack which returns min element in the stack
#include<iostream>
#include<time.h>
using namespace std;

struct node
{
    int data;
    node* next = NULL;

};

//STACK
class myStack
{
    public:
        //variable declaration
        node* top = NULL;
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

int main()
{
  int minVal = 32767; //Arbitrary large value
  myStack s;
  myStack minStack;

  srand(time(NULL));
  int num;

  //push 10 elements on the stack
  for(int i=0; i<10; i++)
  {
      num = rand() %17 + 1;
      s.push(num);
      cout<<"Element pushed: "<<num<<endl;
      if(num<minVal)
      {
          minVal = num;
          minStack.push(minVal);
          cout<<"min Value pushed on minStack: "<<minStack.peek()->data<<endl;
      }
  }

  //Pop 3 values from stack
  for(int i=0; i<3; i++)
  {
      node* popNode = s.pop();
      cout<<"Popped Value: "<<popNode->data<<endl;
      if(popNode->data == minStack.peek()->data)
      {
          node* minPop=  minStack.pop();
          cout<<"min Value Popped: "<<minPop->data<<endl;
          cout<<"new Min Value: "<<minStack.peek()->data<<endl;
      }
  }

  cout<<"Current Min Value: "<<minStack.peek()->data<<endl;
}
