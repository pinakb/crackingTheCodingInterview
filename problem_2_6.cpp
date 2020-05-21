#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct node
{
    char data;
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

string getSequence(node* head)
{
    string seq="";
    node* temp = head;

    while(temp!=NULL)
    {
        seq+= temp->data;
        temp= temp->next;
    }
    return seq;
}

int main()
{
    node* head = (node*) malloc(sizeof(node));
    node* curr = head;
    head->data = 't';
    curr= insertNode(curr, 'a');
    curr= insertNode(curr, 'c');
    curr= insertNode(curr, 'o');
    curr= insertNode(curr, 't');
    curr= insertNode(curr, 'a');
    curr= insertNode(curr, 't');
    displayLL(head);

    string seq1 = getSequence(head);
    string seq2 = seq1;
    reverse(seq2.begin(), seq2.end());

    if(seq1== seq2)
    {
        cout<<"\nLinked List is a palindrome."<<endl;
    }
    else
    {
        cout<<"\nLinked List is not a palindrome."<<endl;
    }

}
