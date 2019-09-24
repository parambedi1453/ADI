#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right=NULL;
    }
};
Node *buildTree(int a[],int i,int n)
{
    if(i>=n)
    return NULL;
    Node *root = new Node(a[i]);
    root->left = buildTree(a,2*i+1,n);
    root->right = buildTree(a,2*i+2,n);
    return root;
}
void printPre(Node *root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}
void printIn(Node *root)
{
    if(root==NULL)
    return;

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}
void printPost(Node *root)
{
    if(root==NULL)
    return;

    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node *root = NULL;
    int a[]={1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(a[0]);
    root = buildTree(a,0,n);

    printPre(root);
    cout<<endl;
    printIn(root);
    cout<<endl;
    printPost(root);
}