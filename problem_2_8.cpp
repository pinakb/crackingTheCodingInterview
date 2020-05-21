#include<iostream>
using namespace std;

struct node
{
    char data;
    int counter;
    node* next = NULL;

};

node* insertNode(node* curr, int data)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->counter=0;
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

node* getNode(node* head, char c)
{
    node* temp = head;
    node* returnNode= NULL;
    while(temp != NULL)
    {
        if(temp->data == c)
        {
            returnNode = temp;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }

    return returnNode;
}

int main()
{
    node* head = (node*) malloc(sizeof(node));
    node* curr = head;
    head->data = 'A';
    head->counter=0;
    curr= insertNode(curr, 'B');
    curr= insertNode(curr, 'C');
    curr= insertNode(curr, 'D');
    curr= insertNode(curr, 'E');
    displayLL(head);
    node* got = getNode(head,'C');

    if(got == NULL)
    {
        cout<<"node not found"<<endl;
    }
    else
    {
        curr->next = got;
        cout<<"cycle generated"<<endl;
    }
    bool flag = true;
    node* temp = head;
    while(flag == true)
    {
        temp->counter++;
        if(temp->counter ==2)
        {
            cout<<"Loop starts at: "<<temp->data<<endl;
            flag = false;
        }
        else
            temp = temp->next;
    }

}
