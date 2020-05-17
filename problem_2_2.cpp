//delete kth element to the last from a singly linked list
//complexity : O(n) i.e length of linked list

#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next = NULL;
};


node* insertNode(node* curr, int data)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    curr->next = newNode;
    curr= newNode;
    return curr;
}

void displayLL(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
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

int main()

{
    int k;
    node* head = (node*) malloc(sizeof(node));
    node* curr = head;
    head->data = 10;
    curr= insertNode(curr, 20);
    curr= insertNode(curr, 30);
    curr= insertNode(curr, 40);
    curr= insertNode(curr, 50);
    curr= insertNode(curr, 60);
    curr= insertNode(curr, 70);
    curr= insertNode(curr, 80);
    curr= insertNode(curr, 90);
    curr= insertNode(curr, 100);
    cout<<"Input Linked List:"<<endl;
    displayLL(head);
    int sizeLL = findSize(head);

    cout<<"size of LL is: "<<sizeLL<<endl;
    cout<<"enter kth to last element to be deleted: ";
    cin>>k;
    cout<<"k= "<<k<<endl;
    if(k>=sizeLL || k<0)
    {
        cout<<"deletion not possible"<<endl;
    }
    else
    {
        int number  = sizeLL-k;
        node* prev = head;
        node* temp = head;
        int checker =1;
        if(number==1)
        {
            node* delNode = head;
            head = head->next;
            temp= head;
            prev = head;
            delete delNode;
        }
        else if(number == sizeLL)
        {
            while(checker != number)
            {
                checker++;
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
        }
        else //if(number >1 && number<sizeLL)
        {
            while(checker != number)
            {
                checker++;
                prev = temp;
                temp = temp->next;
            }
            node* delNode = temp;
            temp = temp->next;
            prev->next = temp;
            delete delNode;
        }
    }

    cout<<"\noutput linked list"<<endl;
    displayLL(head);
}
