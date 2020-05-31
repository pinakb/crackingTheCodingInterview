#include<iostream>
#include<vector>
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
    cout<<root->data<<"\t";
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
    cout<<root->data<<"\t";
    inOrder(root->right);
}

node* arrayToBST(int arr[], int startIndex, int endIndex)
{
    if(startIndex > endIndex)
        return NULL;
    int mid = (endIndex+startIndex)/2;
    node* root = newNode(arr[mid]);
    root->left= arrayToBST(arr, startIndex, mid-1);
    root->right = arrayToBST(arr, mid+1, endIndex);

    return root;
}

int main()
{
    int input[]=  {1,2,3,4,5,6,7,8,9,10,11,12};
    int n = sizeof(input)/sizeof(input[0]);
    node* tree= arrayToBST(input, 0, n-1);
    cout<<"preFix of the tree: "<<endl;
    preOrder(tree);
    cout<<endl;
    cout<<"infix of the tree: "<<endl;
    inOrder(tree);
    cout<<endl;

}
