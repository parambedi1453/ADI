/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list, You have to complete the below functions only */
int countNode(struct Node* head)
{
  
  struct Node *ptr = head;
  int c=0;
  while(ptr!=NULL)    
  {
    c++;
    ptr=ptr->next;
  }
  return c;
}
int findMiddle(struct Node* head) 
{
  if(head == NULL || head->next==NULL)
    return -1;
	int c = countNode(head);
  	c=(c/2)+1;
  	int d =0;
  struct Node *ptr;
  ptr=head;
  while(ptr!=NULL)
  {
    d++;
    if(c==d)
    {
      return ptr->data;
      
    }
    ptr=ptr->next;
  }
  
}

int findNLast(struct Node* head, int n)
{
  if(head == NULL || head->next==NULL)
    return -1;
	int c = countNode(head);
  	c = c-n+1;
   struct Node *ptr=NULL;
  ptr=head;
  if(c>0)
  {
    int d=0;
    
  while(ptr!=NULL)
  {
    d++;
    if(c==d)
    {
      return ptr->data;
    }
    ptr=ptr->next;
  }
  }
  else
  {
    while(ptr->next!=NULL)
      ptr=ptr->next;
   return ptr->data;
  }
}


