Node* MergeLists(Node *headA, Node* headB)
{
    if((!headB) && (!headA))
    {
        return NULL;
    }
    if(!headA)
    {
        return headB;
    }
    if(!headB)
    {
        return headA;
    }
    
    else
    {
            if(headA->data < headB->data)
            {
                headA->next = MergeLists(headA->next, headB);
                return headA;
            }
            else
            {
                headB->next = MergeLists(headA, headB->next);
                return headB;
            }
    }
}