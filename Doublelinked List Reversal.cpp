Node* Reverse(Node* head)
{    
    if(!head) return NULL;
    Node* current= head;
    
    Node* buffer = current->prev;
    current->prev = current->next;
    current->next = buffer;
    current = current->prev;
    
    if(!current) return head;
    else
    {
        return Reverse(current);
    }
}