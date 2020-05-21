//problem Statement: two numbers represented by a linked list, where each node contains a single
//digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
//function that adds the two numbers and returns the sum as a linked list.
//complexity= O(n)


#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
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
    curr= curr->next;
    return curr;
}

void displayLL(node* head)
{
    node* curr = head;
    while(curr != NULL)
    {
        cout<<curr->data<<"\t";
        curr = curr->next;
    }
    cout<<"\n";
}

string traversLL(node* head)
{
    node* curr = head;
    string seq="";
    while(curr != NULL)
    {
        seq += to_string(curr->data);
        curr = curr->next;
    }
    return seq;
}

int main()
{
    node* head1 = (node*) malloc(sizeof(node));
    node* curr1 = head1;
    head1->data = 3;
    curr1= insertNode(curr1, 5);
    curr1= insertNode(curr1, 8);
    curr1= insertNode(curr1, 5);


    node* head2 = (node*) malloc(sizeof(node));
    node* curr2 = head2;
    head2->data = 5;
    curr2= insertNode(curr2, 9);
    curr2= insertNode(curr2, 2);

    cout<<"input LinkedList: "<<endl;
    displayLL(head1);
    displayLL(head2);

    string num1= traversLL(head1);
    string num2= traversLL(head2);
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    int n1 = 0;
    int n2 = 0;
    stringstream cast1(num1);
    cast1>>n1;
    stringstream cast2(num2);
    cast2>>n2;
    int sum = n1+n2;

    string sumString = to_string(sum);
    reverse(sumString.begin(), sumString.end());

    node* newHead = (node*) malloc(sizeof(node));
    newHead->data = sumString[0] - '0';
    node* newCurr = newHead;

    for(int i=1; i< sumString.length(); i++)
    {
        int d = sumString[i] - '0';
        newCurr = insertNode(newCurr,d);
    }
    cout<<"Output LinkedList: "<<endl;
    displayLL(newHead);
}


