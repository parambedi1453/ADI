#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    this->data=data;

};
void push(Node &head,int data)
{
    Node *ptr=new Node(data);
    Node *temp = head;
    ptr->next=head;

    if(head!=NULL)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next = ptr;
    }
    else
    ptr->next = ptr;

    head = ptr;
}
int main()
{

}