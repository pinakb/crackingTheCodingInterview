//Inorder Successor of the input node

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

struct node* newNode(int data){

    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void searchNode(node* root, node** fromNode, int input)
{
    if(root == NULL)
    {
        return;
    }
    if(root->data == input)
    {
        *fromNode = root;
    }
    searchNode(root->left, fromNode, input);
    searchNode(root->right, fromNode, input);
}

void inOrderSuccessor(node* root, int *getResult)
{
    static bool flag = false;
    if(root == NULL)
    {
        return;
    }
    inOrderSuccessor(root->left, getResult);
    if(flag == false)
    {
        *getResult= root->data;
        flag = true;
    }
    return;
    //inOrderSuccessor(root->right, getResult);
}

int findSuccessor(node* root, int input)
{
    static node* fromNode;
    searchNode(root, &fromNode, input);
    cout<<"found Node: "<<fromNode->data<<endl;
    int getResult;
    if(fromNode->right ==NULL)
    {
        return fromNode->data;
    }
    else
    {
        fromNode = fromNode->right;
        inOrderSuccessor(fromNode, &getResult);
    }
    //int result = inOrderSuccessor(fromNode);
    return getResult;
}

int main()
{
    struct node* root = newNode(6);
    root->left = newNode(4);
    root->right = newNode(10);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(9);
    root->right->left->left = newNode(8);
    root->right->right = newNode(12);
    root->right->right->left = newNode(11);
    root->right->right->right = newNode(15);

    int inputNode = 4;
    int successor = findSuccessor(root, inputNode);
    cout<<"inorder successor : "<<successor<<endl;
}

