//Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
//composed of several stacks and should create a new stack once the previous one exceeds capacity.
//SetOfStacks. push () and SetOfStacks. pop () should behave identically to a single stack
//(that is, pop ( ) should return the same values as it would if there were just a single stack).

#include<iostream>
#include<vector>

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

class setOfStacks: public myStack{

public:
    void push(int d);
    node* pop();
    node* popAt(int i);
    node* peek();
    vector<myStack> sos;
    bool flag= false;

//private:
    int threshold = 4;
    int checker;
    int index=0;


};

void setOfStacks::push(int d)
{
    if(index==0 && flag == false)
    {
        sos.push_back(myStack());
        checker=0;
        flag=true;
    }
    if(checker==4)
    {
        sos.push_back(myStack());
        index++;
        checker=0;
    }
    sos[index].push(d);
    checker++;
}
node* setOfStacks::pop()
{
    bool flag = sos[index].isEmpty();
    if(flag == true)
    {
        index--;
    }
    node* poppedNode= sos[index].pop();
    return poppedNode;
}

node* setOfStacks::popAt(int userIndex)
{
    node* returnNode = sos[userIndex].pop();
    return returnNode;
}

node* setOfStacks::peek()
{
    node* returnNode = sos[index].peek();
    return returnNode;
}

int main()
{
    setOfStacks s;

    //pushing arbitrary 10 values to stack
    for(int i=0; i<10; i++)
    {
        s.push(i+1);
        cout<<"pushed: "<<i+1<<endl;
    }
    cout<<"peek: "<<s.peek()->data<<endl;
    cout<<"count of sub-Stacks: "<<s.index+1<<endl;
    //popAt index 1
    node* popatNode= s.popAt(1);
    cout<<"Value popped at index "<<1<<": "<<popatNode->data<<endl;

    //regular pop
    node* regularPop = s.pop();
    cout<<"Value popped using regular pop: "<<regularPop->data<<endl;
    //new peek of stack
    cout<<"peek: "<<s.peek()->data<<endl;

    for(int i=10; i<=20; i++)
    {
        s.push(i+1);
        cout<<"pushed: "<<i+1<<endl;
    }
    cout<<"count of sub-Stacks: "<<s.index+1<<endl;
    cout<<"peek: "<<s.peek()->data<<endl;
    popatNode= s.popAt(1);
    cout<<"Value popped at index "<<1<<": "<<popatNode->data<<endl;

}
