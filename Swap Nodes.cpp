#include <vector>
#include <iostream>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
};

void treeInput(vector<node*> tree)
{
    int commandCount;
    cin>>commandCount;
    
    int a, b;
    char space;
    
    
    for(int i=1; i <= commandCount; i++)
    {
        cin>>a>>space>>b;
        
        if(a>-1)
        {
            tree[i]->left->data= a;
            tree.push_back(tree[i]->left);
        }
        
        if(b>-1)
        {
            tree[i]->right->data= b;
            tree.push_back(tree[i]->right);
        }
    }
}

void treePrint(node* current)
{
	if(!current) 
    {
        return;
    }
    
	treePrint(current->left);
	cout<<current->data<<" ";
	treePrint(current->right); 
}

int main() 
{
    vector<node*> binaryTree;
    node* root;
    root->data=1;
    binaryTree.push_back(root);
    
    treeInput(binaryTree);
    
    vector<int> treeStructure;
    treeStructure.push_back(1);
    
    for(int j=1; j <= binaryTree.size(); j++)
    {
        if(binaryTree[j]==binaryTree[j-1]->left || binaryTree[j]==binaryTree[j-1]->right)
        {
            treeStructure.push_back(1);
        }
        else
        {
            ++treeStructure.back();
        }
    }
    
    int swapCount;
    cin>>swapCount;
    
    for(int k=0; k < swapCount; k++)
    {
        int swapLevel;
        cin>>swapLevel;
        swapLevel--;
        
        int sum=0;
        
        for(int l=0; l < swapLevel; l++)
        {
            sum += treeStructure[l];
        }
        
        for(int m=0; m < treeStructure[swapLevel]; m++)
        {
            node * buffer = binaryTree[sum+m]->left;
            binaryTree[sum+m]->left = binaryTree[sum+m]->right;
            binaryTree[sum+m]->right = buffer;
        }
        treePrint(binaryTree.front());
    }
    return 0;
}