//Algorithm to get list of depths.
//output: lists of nodes from each level

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

vector<vector<node*>> listOfLevels(node* root)
{
    vector<vector<node*>> result;
    vector<node*> currentLevel;
    if(root!=NULL)
    {
        currentLevel.push_back(root);
    }

    while(currentLevel.size()>0)
    {
        result.push_back(currentLevel);
        vector<node*> parents = currentLevel;
        currentLevel.clear();
        for(int i=0; i<parents.size(); i++)
        {
            if(parents[i]->left != NULL)
            {
                currentLevel.push_back(parents[i]->left);
            }
            if(parents[i]->right !=NULL)
            {
                currentLevel.push_back(parents[i]->right);
            }
        }
    }

    return result;
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

    vector<vector<node*>> result = listOfLevels(root);

    for(int i=0; i< result.size(); i++)
    {
        cout<<"Level: "<<i<<endl;
        for(int j=0; j< result[i].size(); j++)
        {
            cout<<result[i][j]->data<<" ";
        }
        cout<<"\n";
    }
}
