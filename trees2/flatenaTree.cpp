#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public :
    int data;
    Node *left;
    Node *right;
    Node (int d)
    {
        data = d;
        left =NULL;
        right = NULL;
    }
};
class ListNode
{
    public :
    Node *head;
    Node *tail;
};
Node* insert(Node *root,int data)
{
    if(root==NULL)
    {
        Node *temp = new Node(data);
        return temp;
    }
    if(data>root->data)
    root->right = insert(root->right,data);
    else
    root->left = insert(root->left,data);

    return root;
}

ListNode flatenTree(Node *root)
{
    ListNode l;

    if(root==NULL)
    {
        l.head=NULL;
        l.tail = NULL;
        return l;
    }
    //if only the leaf node exist
    if(root->left==NULL &&root->right==NULL)
    {
        l.head = root;
        l.tail = root;
        return l;
    }
    //if rightsubtre is NULL
    if(root->left!=NULL && root->right==NULL)
    {
       ListNode leftlist = flatenTree(root->left);
       leftlist.tail->right = root;
       l.head = leftlist.head;
       l.tail = root; 
        return l;
    }
    //if leftsubtreee is NULL
    if(root->right!=NULL && root->left==NULL)
    {
        ListNode rightlist = flatenTree(root->right);
        l.head=root;
        l.head->right = rightlist.head;
        l.tail = rightlist.tail;
        return l;
    }
    ListNode leftlist = flatenTree(root->left);
    ListNode rightlist = flatenTree(root->right);
  
    leftlist.tail->right= root;
    root->right=rightlist.head;

    l.head = leftlist.head;
    l.tail = rightlist.tail;
    return l;
}
int main()
{
    Node *root = NULL;
    root = insert(root,5);
    insert(root,3);
    insert(root,1);
    insert(root,7);
    insert(root,6);
    insert(root,8);

    ListNode l = flatenTree(root);
    Node *temp = l.head;
    while(temp)
    {
        cout<<temp->data<<"->";
        temp = temp->right;
    }
   
}