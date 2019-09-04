/*
    worst case is skew tree which is like link list
    o(n^2);
    this recursive approch for level order printing of tree
*/

#include<iostream>
using namespace std;
class Node
{
    public :
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left=NULL;
        right=NULL;
    }
};

int height(Node *root)
{
    if(root==NULL)
    return 0;
    
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1,h2)+1;
}
void printklevel(Node *root,int k)
{
    if(k==1)
    {
        cout<<root->data<<" ";
        return ;
    }
    printklevel(root->left,k-1);
    printklevel(root->right,k-1);
    return;
}
void printlevel(Node *root)
{
     int h = height(root);
    for(int i=1;i<=h;i++)
    {
        printklevel(root,i);
        cout<<endl;
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right=new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
   
    cout<<height(root);
    cout<<endl;

    printlevel(root);
   
}