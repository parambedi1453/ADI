#include<iostream>
using namespace std;
class Node
{
    public :
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insertAtHead(Node * &head,int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;

}
void insertAtTail(Node *&head,int data)
{
    if(head==NULL)
    {
        head = new Node(data);
        return;
    }
    Node *tail = head;
    while(tail->next !=NULL)
    tail = tail->next;
    tail->next = new Node(data);
    return ;
}
void dissplayList(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void insertAtMidle(Node *&head,int data,int pos)
{
    if(head==NULL)
    {
        head = new Node(data);
        return ;
    }
    int p =1;
    Node * temp = head;
    while(p!=pos-1)
    {temp=temp->next;
    p++;}

    Node * n = new Node(data);
    n->next = temp->next;
    temp->next = n;
}
int recursivelength(Node *head)
{
    if(head==NULL)
    return 0;

    return 1+recursivelength(head->next);
}
void deleteAtHead(Node *&head)
{
    if(head==NULL)
    return;
    Node *temp = head;
    head = head->next;
    delete temp;
}
void deleteAtTail(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    while(temp->next!=NULL)
    {
        prev = temp;
        temp=temp->next;
    }
    delete temp;
    prev->next = NULL;
}
bool recursiveSearch(Node *head,int key)
{
    if(head == NULL)
    return false;
    else if(head->data == key)
    return true;
    else
    return recursiveSearch(head->next,key);
}

// +++++++++++++++ MAIN ++++++++++++++++++++++
int main()
{
    Node *head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,7);
    insertAtTail(head,9);
    insertAtMidle(head,65,3);
    dissplayList(head);

    cout<<recursivelength(head)<<endl;

    deleteAtHead(head);
    dissplayList(head);

    deleteAtTail(head);
    dissplayList(head);

    int e ;
    cin>>e;

    cout<<recursiveSearch(head,e)<<endl;

}

/*

 NTH NODE FROM THE END
int flen(Node *head)
{
    int c=0;
    while(head!=NULL)
    {
        c++;
        head=head->next;
    }
    return c;
}
int getNthFromLast(Node *head, int n)
{
    if(n>flen(head))
        return -1;
        Node * p = head;
        Node *s = head;
      for(int i=1;i<=n;i++)
      {
        p=p->next;
      }
      while(p!=NULL)
      {
          p=p->next;
          s=s->next;
      }
      return s->data;
}

*/
