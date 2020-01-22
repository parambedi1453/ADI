/*This is a function problem.You only need to complete the function given below*/
/*  the node structure is as follows
struct Node {
    int data;
    Node *next;
    Node *arb;
    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/
// Should return the head of the copied linked list the
// output will be 1 if successfully copied
Node *copyList(Node *head) {
    if(head==NULL)
    return NULL;
    // Your code here
    map<Node*,Node*> m;
    
    Node *newHead = new Node(head->data);
    m[head] = newHead;
    Node *ptr,*nptr;
    ptr=head->next;
    nptr=newHead;
    
    while(ptr)
    {
        Node *temp = new Node(ptr->data);
        nptr->next = temp;
        m[ptr] = temp;
        nptr=temp;
        ptr=ptr->next;
    }
    ptr=head;
    while(ptr)
    {
        if(ptr->arb)
        {
            Node *temp = m[ptr];
            temp->arb = m[ptr->arb];
        }
        ptr=ptr->next;
    }
    return newHead;
}