#include <iostream>
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
Node* insertAtTail(Node *head,int data)
{
    if(head == NULL)
    {
        head = new Node(data);
        return head;
    }
    else
    {
        Node *ptr = head;
        while(ptr->next != NULL)
        ptr = ptr->next;

        ptr->next = new Node(data);
    }
    return head;
}
Node* evenodd(Node* head)
{
    Node *ptr=head,*eptr = NULL,*optr = NULL,*e=NULL,*o=NULL;
    int ef=0,of=0;
    while(ptr!=NULL)
    {
        if(ptr->data%2==0)
        {
            if(ef==0)
           {
                e = ptr;
              eptr = ptr;
              ef=1;
           }
           else
           {
                eptr->next = ptr;
                eptr=ptr;
           }
        }
        else
        {
           if(of == 0)
           {
                o = ptr;
                optr = ptr;
                of =1;
           }
           else
           {
               optr->next = ptr;
               optr=ptr;
           }
        }
        ptr= ptr->next;
    }
    if(e==NULL)
    {
        optr->next = NULL;
        return o;
    }
    else if(o==NULL)
    {
        eptr->next = NULL;
        return e;
    }
   else if(e!=NULL && o!=NULL)
    {
        optr->next = NULL;
        eptr->next = o;
        return e;
    }

}
int main() {

    int t,n,data;
    cin>>t;
    while(t--)
    {
        cin>>n;
        Node *head = NULL;
        for(int i=0;i<n;i++)
        {
            cin>>data;
            head = insertAtTail(head,data);
        }
        Node *ptr = evenodd(head);
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;

    }
	//code
	return 0;
}

/*


Input
3
7
17 15 8 9 2 4 6
4
1 3 5 7
7
8 12 10 5 4 1 6

Output
8 2 4 6 17 15 9
1 3 5 7
8 12 10 4 6 5 1

*/
