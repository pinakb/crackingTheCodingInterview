//Algorithm to check first common ancestor

#include<iostream>
#include<string>

using namespace std;

struct node{
    int data;
    string color;
    node* left;
    node* right;
    node* parent;

};

struct node* newNode(int data, node* parent){

    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->color= "NULL";
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;
    return node;
};

void preOrder(node* root)
{
    if(root ==NULL)
    {
        return;
    }
    cout<<root->color<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void dfsColor(node* root, int a, string color)
{
    if(root == NULL)
    {
        return;
    }
    if(root->data == a)
    {
        root->color = color;
        node* temp = root;
        while(temp->parent != NULL)
        {
            temp =temp->parent;
            if(temp->color == "NULL")
            {
                temp->color= color;
            }
            else
            {
                temp->color = "MIX";
            }
        }
    }
    dfsColor(root->left, a, color);
    dfsColor(root->right, a, color);

}

void firstCommonAncestor(node* root, int *result)
{
    if(root == NULL)
    {
        return;
    }
    if(root->color == "MIX")
    {
        if(root->left->color!= "MIX" && root->right->color!= "MIX")
        {
            *result = root->data;
        }
    }
    firstCommonAncestor(root->left, result);
    firstCommonAncestor(root->right, result);
}

void lca(node* root, int a, int b)
{
    dfsColor(root, a, "green");
    cout<<"Green color of: "<<a<<endl;
    preOrder(root);
    cout<<"\n";
    cout<<"Yellow color of: "<<b<<endl;
    dfsColor(root, b, "yellow");
    preOrder(root);
    int result;
    firstCommonAncestor(root, &result);
    cout<<"\n\nfirst common ancestor: "<<result<<endl;
}

int main()
{
    //newNode Arguments: 1st Arg= data, 2nd Arg = Parent
    struct node* root = newNode(1, NULL);
    root->left = newNode(2, root);
    root->right= newNode(3, root);
    //Left Subtree
    root->left->left= newNode(4, root->left);
    root->left->right= newNode(5, root->left);
    root->left->left->left= newNode(11,root->left->left);
    root->left->left->right= newNode(12, root->left->left);
    root->left->left->right->left= newNode(13, root->left->left->right);
    root->left->left->right->right= newNode(14, root->left->left->right);

    //Right Subtree
    root->right->left= newNode(6, root->right);
    root->right->right= newNode(7, root->right);
    root->right->left->left= newNode(8, root->right->left);
    root->right->left->right= newNode(9, root->right->left);
    root->right->right->left= newNode(10, root->right->right);

    //preOrder(root);
    lca(root, 8,9);
}
