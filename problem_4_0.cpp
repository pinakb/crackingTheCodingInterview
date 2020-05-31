#include<iostream>
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

void preOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<endl;
    inOrder(root->right);
}

void postOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<endl;

}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    cout<<"preOrder Traversal\n";
    preOrder(root);
    cout<<"\n";
    cout<<"inOrder Traversal\n";
    inOrder(root);
    cout<<"\n";
    cout<<"postOrder Traversal\n";
    postOrder(root);
    cout<<"\n";
}
