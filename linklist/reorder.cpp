  
void func(ListNode *f,ListNode *s)
{
   static ListNode *temp=NULL;
    
    if(f->next==NULL)
    {
        temp=s->next;
        s->next = NULL;
        return ;
    }
    else if(f->next->next==NULL)
    {
        temp=s->next->next;
        s->next->next  = NULL;
        return ;
    }
    func(f->next->next,s->next);
    
        ListNode *ptr = temp;
        temp = temp->next;
        ptr->next = s->next;
        s->next = ptr;
        
    
}
ListNode* Solution::reorderList(ListNode* head) {
    
    if(head==NULL)
    return head;
    func(head,head);
    return head;
}
