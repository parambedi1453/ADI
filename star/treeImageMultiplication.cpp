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
int imageMultiply(Node *root1,Node *root2)
{
 
    if(root1==NULL || root2==NULL)
    return 0;
    else
    {
         int a = imageMultiply(root1->left,root2->right);
         int b = imageMultiply(root1->right,root2->left);
         int c =a+b+(root1->data*root2->data);
         return c;
    }
    
}
int main()
{
    Node *root = NULL;
    root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    int s = (root->data*root->data)+imageMultiply(root->left,root->right);
    cout<<s<<endl;
}