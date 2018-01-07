node *lca(node *root, int v1,int v2)
{
    node * temp= root;
    while(temp->data>v1 && temp->data>v2)
    {
        temp= temp->left;
    }
    
    while(temp->data<v1 && temp->data<v2)
    {
        temp= temp->right;
    }
    
    return temp;
}