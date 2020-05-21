//code to partition a linked list around a value x, such that all nodes less than x come
//before all nodes greater than or equal to x. lf x is contained within the list, the values of x only need
//to be after the elements less than x (see below). The partition element x can appear anywhere in the
//"right partition"; it does not need to appear between the left and right partitions.
//complexity : O(n) i.e length of linked list

#include<iostream>

using namespace std;

struct node
{
    int data;
    bool visited;
    node* next = NULL;
};

node* insertNode(node* curr, int data)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->visited = false;
    curr->next = newNode;
    curr= newNode;
    return curr;
}

void displayLL(node* head)
{
    node* curr = head;
    while(curr != NULL)
    {
        cout<<curr->data<<endl;
        curr = curr->next;
    }
}

int findSize(node* head)
{
    node* temp = head;
    int counter=0;

    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

int countSmall(node* head, int part)
{
    node* temp = head;
    int counter=0;

    while(temp!= NULL)
    {
        if(temp->data <part)
        {
            counter++;
        }
        temp= temp->next;
    }
    return counter;
}
int findSmall(node* head, int part)
{
    node* temp = head;
    int d;
    bool flag = true;
    while(flag == true)
    {
        if(temp->data < part && temp->visited == false)
        {
            d = temp->data;
            temp->visited = true;
            flag = false;
        }
        else
        {
            temp = temp->next;
        }
    }
    return d;
}

int findMaxNode(node* head)
{
    int maxValue =0;
    node* maxNode= NULL;
    node* temp = head;

    while(temp!= NULL)
    {
        if(temp->data > maxValue)
        {
            maxValue =temp->data;
            maxNode = temp;
        }
        temp = temp->next;
    }
    maxNode->visited = true;
    return(maxNode->data);
}

int findRemainingNode(node* head, int part)
{
    node* temp = head;
    int d;
    bool flag = true;
    while(flag == true)
    {
        if(temp->data >= part && temp->visited == false)
        {
            d = temp->data;
            temp->visited = true;
            flag = false;
        }
        else
        {
            temp = temp->next;
        }
    }
    return d;
}


int main()

{
    node* head = (node*) malloc(sizeof(node));
    node* curr = head;
    head->data = 3;
    curr= insertNode(curr, 5);
    curr= insertNode(curr, 8);
    curr= insertNode(curr, 5);
    curr= insertNode(curr, 10);
    curr= insertNode(curr, 2);
    curr= insertNode(curr, 1);
    cout<<"Input Linked List:"<<endl;
    displayLL(head);
    int part;
    cout<<"Enter partition value: ";
    cin>>part;
    int sizeLL = findSize(head);
    int smallCount= countSmall(head, part);
    int maxValue = findMaxNode(head);

    node* newHead = (node*) malloc(sizeof(node));
    newHead->next= NULL;
    newHead->data = -1;
    node* newCurr = newHead;

    for(int i=0; i<smallCount; i++)
    {
        int d = findSmall(head, part);
        newCurr = insertNode(newCurr, d);
    }
    newCurr = insertNode(newCurr,maxValue);
    int remainingNodeCount = sizeLL - smallCount -1;
    for(int i=0; i< remainingNodeCount; i++)
    {
        int d = findRemainingNode(head, part);
        newCurr = insertNode(newCurr,d);
    }

    node* delNode = newHead;
    newHead = newHead->next;
    delete delNode;
    displayLL(newHead);
}

