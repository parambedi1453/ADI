/*This is a function problem.You only need to complete the function given below*/
/* Following is the Linked list node structure */
/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node *ptr;
void rlist(Node *s,Node *f)
{
    if(f->next==NULL)
    {
        ptr=s->next;
        s->next=NULL;
        return ;
    }
    else if(f->next->next==NULL)
    {
        ptr=s->next->next;
        s->next->next=NULL;
        return ;
    }
    rlist(s->next,f->next->next);
    Node *temp = s->next;
    s->next = ptr;
    Node *ptrnext = ptr->next;
    ptr->next = temp;
    ptr= ptrnext;
}
void reorderList(Node* head) 
{
    ptr=NULL;
    rlist(head,head);
    // Your code here
}