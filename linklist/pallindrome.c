/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list, You have to complete the below functions only */
struct Node * findHead(struct Node *head)
{
  struct Node *p =head,*q = head,*head2=NULL;
  while(1)
  {
    p=p->next->next;
   
    if(p == NULL)
    {
      head2=q->next;
      q->next=NULL;
      return head2;
    }
     else if(p->next == NULL)
    {
      head2 = q->next->next;
      q->next=NULL;
      return head2;
    }
    q=q->next;
  }
}
int  checkPalindrome(struct Node* head) 
{
 if(head==NULL)
    return 0;
  if(head->next==NULL)
    return 1;
	struct Node *head2 = NULL,*ptr1=NULL,*ptr2=NULL;
  head2 = findHead(head);
  struct Node *curr = head2,*prev=NULL,*next = NULL;
  while(curr!=NULL)
  {
    next = curr->next;
    curr->next=prev;
    prev =curr;
    curr = next;
  }
 
  head2 = prev;
  ptr1 = head;
  ptr2 = head2;
  while(ptr1!=NULL && ptr2!=NULL)
  {
    if(ptr1->data != ptr2->data)
      return 0;
    ptr1=ptr1->next;
    ptr2=ptr2->next;
  }
  return 1;
}