int height(Node* root) 
{
    if (!root) 
    {
        return -1;
    }

    int lefthSubTree = height(root->left);
    int righthSubTree = height(root->right);

    if (lefthSubTree > righthSubTree) 
    {
        return lefthSubTree + 1;
    } 
    
    else 
    {
        return righthSubTree + 1;
    }
}