//Algorithm to check if tree is balanced.

#include<iostream>
#include<vector>
#include<math.h>
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

int htOfTree(node* root)
{
    if(root ==NULL)
    {
        return -1;
    }
    int leftH= htOfTree(root->left);
    int rightH= htOfTree(root->right);

    if(leftH > rightH)
    {
        return leftH +1;
    }
    else
    {
        return rightH +1;
    }
}

bool isBalanced(node* root)
{
    if(root==NULL)
    {
        return true;
    }
    int leftHeight = htOfTree(root->left);
    int rightHeight = htOfTree(root->right);
    if(abs(leftHeight-rightHeight)>1)
    {
        return false;
    }
    isBalanced(root->left);
    isBalanced(root->right);

}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->right = newNode(6);


    bool result = isBalanced(root);
    cout<<"isBalanced? :"result<<endl;
}
