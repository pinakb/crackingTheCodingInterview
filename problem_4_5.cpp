//Algorithm to check if tree is BST?

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

void inOrder(node* root, vector<int> *result)
{
    if(root ==NULL)
    {
        return;
    }
    inOrder(root->left, result);
    result->push_back(root->data);
    inOrder(root->right, result);
}


bool isBST(node* root)
{
    static vector<int> result;
    inOrder(root, &result);
    vector<int> temp = result;
    sort(temp.begin(), temp.end());

    for(int i=0; i<result.size(); i++)
    {
        if(temp[i] == result[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    cout<<endl;

    return true;
}


int main()
{
    struct node* root = newNode(6);
    root->left = newNode(4);
    root->right = newNode(10);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(9);


    bool result = isBST(root);
    cout<<"isBST? : "<<result<<endl;
}
