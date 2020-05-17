#include<iostream>
#include<set>
#include<unordered_map>

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

unordered_map<int, int> initMap(unordered_map<int, int> checker, node* head)
{
    set<int>uniqueNode;
    set<int>::iterator itr;
    node* temp = head;

    while(temp!=NULL)
    {
        uniqueNode.insert(temp->data);
        temp = temp->next;
    }


    for(itr= uniqueNode.begin(); itr!= uniqueNode.end(); ++itr)
    {
        checker[*itr]=0;
    }
    return checker;
}

unordered_map<int, int> populateMap(unordered_map<int, int> checker, node* head)
{
    unordered_map<int,int>::iterator locator;
    node* temp = head;

    while(temp != NULL)
    {
        int d= temp->data;
        locator = checker.find(d);
        int value = locator->second;
        locator->second = value+1;
        temp = temp->next;
    }

    return checker;
}

node* deleteDups(unordered_map<int, int> checker, node* head)
{
    node*temp = head;
    node* prev = head;
    unordered_map<int, int>::iterator locator;
    while(temp != NULL)
    {
        int d = temp->data;
        locator = checker.find(d);
        if(locator->second >1)
        {

            if(locator->first == head->data)
            {
                node* delNode = head;
                head=  head->next;
                temp= head;
                prev= head;
                delete delNode;
                locator->second -=1;
            }
            else
            {
                node* delNode = temp;
                temp= temp->next;
                prev->next = temp;
                delete delNode;
                locator->second -=1;
            }
        }
        else
        {
            prev= temp;
            temp= temp->next;
        }
    }
    return head;
}

int main()
{
    node* head = (node*) malloc(sizeof(node));
    node* curr = head;
    head->data = 30;
    curr= insertNode(curr, 10);
    curr= insertNode(curr, 10);
    curr= insertNode(curr, 30);
    curr= insertNode(curr, 40);
    curr= insertNode(curr, 50);
    curr= insertNode(curr, 40);
    cout<<"Input Linked List:"<<endl;
    displayLL(head);

    unordered_map<int, int>checker;
    checker = initMap(checker, head);
    checker = populateMap(checker, head);
    head= deleteDups(checker, head);
    cout<<"\nOutput LinkedList: "<<endl;
    displayLL(head);
}
