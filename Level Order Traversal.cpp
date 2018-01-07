#include <queue>

void levelOrder(node * root) 
{
    queue<node*> traversal;
    traversal.push(root);
    node * temp;
    
    do
    {
        temp=traversal.front();
        
        if(temp->left)
        {
            traversal.push(temp->left);
        }
        
        if(temp->right)
        {
            traversal.push(temp->right);
        }
        
        traversal.pop();
        cout<<temp->data<<" ";
        
    } while(!traversal.empty());
  
}