#include<iostream>
#include<queue>

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

int countNodes(node* root)
{
    static int counter=0;
    if(root==NULL)
    {
        return 0;
    }
    counter++;
    countNodes(root->left);
    countNodes(root->right);
    return counter;
}

void bfs(node* root)
{
    int nodeCount =0;
    //static int counter=0;
    nodeCount= countNodes(root);
    queue<node*> bfsQueue;
    if(root)
    {
        bfsQueue.push(root);
        cout<<root->data<<" ";
    }
    else
    {
        cout<<"NULL";
    }
    while(!bfsQueue.empty())
    {

        node* temp_node = bfsQueue.front();
        bfsQueue.pop();

        if(temp_node->left)
        {
            bfsQueue.push(temp_node->left);
            cout<<temp_node->left->data<<" ";
        }
        if(temp_node->right)
        {
            bfsQueue.push(temp_node->right);
            cout<<temp_node->right->data<<" ";
        }
    }
}

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

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    bfs(root);

    int height = htOfTree(root);
    cout<<"\nheight of tree: "<<height<<endl;
}
