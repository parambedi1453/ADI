/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list, You have to complete the below functions only */

struct Node* findMergePoint(struct Node* head1, struct Node* head2) 
{
 
  
	struct Node * ptr1 = head1,*ptr2=head2;
  while(ptr1!=NULL)
  {
    ptr2=head2;
    while(ptr2!=NULL)
    {
      if(ptr1->next ==ptr2->next)
      {
        return ptr1->next;
      }
      ptr2=ptr2->next;
    }
    ptr1=ptr1->next;
  }
  return NULL;
}