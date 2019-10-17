struct Node {
    int val;
    struct Node* next;
}; */
void intersection(Node **head1, Node **head2,Node **head3)
{
   struct Node *p = *head1;
    struct Node *q = *head2;
    // if(*head1 == NULL && *head2 == NULL)
    // {
    //     *head3=NULL;
    //     return;
    // }
    *head3 = NULL;
    while(p!=NULL && q!=NULL)
    {
        if(p->val<q->val)
        p=p->next;
        else if(p->val>q->val)
        q=q->next;
        else
        {
           struct  Node *temp = (struct Node *)malloc(sizeof(struct Node));
            temp->val = p->val;
            temp->next = NULL;
            if(*head3 == NULL)
            {
                *head3 = temp;
            }
            else
            {
               struct  Node *ptr = *head3;
                while(ptr->next!=NULL)
                ptr=ptr->next;
                ptr->next = temp;
            }
            p=p->next;
            q=q->next;
        }
    }
    return;
    // Your Code Here
}



/*

    Input
    1                       -->  (No of test cases)
    5 4                    -->  (sizes of linked lists)
    1 2 3 4 6           -->  (Elements of 1st linked list)
    2 4 6 8              -->  (Elements of 2nd linked list)
    4 2
    10 20 40 50
    15 40

    Output
    2 4 6                 -->  (Elements of resultant 3rd linked list
    40

*/
